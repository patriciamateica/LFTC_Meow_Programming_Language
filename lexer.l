%option noyywrap yylineno

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "symtab.h"

#define LEN        64
#define MAX        128
#define CODE_ID    0
#define CODE_CONST 1

/* ---------- Token list (read from tokens.in) ---------- */
typedef struct { char text[LEN]; int code; } Token;

static Token tok[MAX];
static int ntok;

static int load_tokens(const char *path) {
    FILE *f = fopen(path, "r");
    if (!f) {
        perror(path);
        return -1;
    }
    char line[256];
    while (fgets(line, sizeof line, f) && ntok < MAX) {
        size_t n = strlen(line);
        while (n > 0 && isspace((unsigned char)line[n - 1])) line[--n] = '\0';
        char *p = line;
        while (*p == ' ' || *p == '\t') p++;
        if (*p == '\0' || *p == '#') continue;
        strcpy(tok[ntok].text, p);
        tok[ntok].code = ntok + 2;
        ntok++;
    }
    fclose(f);
    return 0;
}

static int token_code(const char *s) {
    for (int i = 0; i < ntok; i++)
        if (strcmp(tok[i].text, s) == 0) return tok[i].code;
    return -1;
}

/* ---------- Finite automata (read from the fa_*.in files) ---------- */
typedef struct { char from[LEN], sym[LEN], to[LEN]; } Trans;

typedef struct {
    Trans t[MAX];
    int nt;
    char finals[MAX][LEN];
    int nf;
    char initial[LEN];
} FA;

static FA fa_id, fa_num, fa_str;

static int read_fa(const char *path, FA *fa) {
    FILE *f = fopen(path, "r");
    if (!f) {
        perror(path);
        return -1;
    }
    char line[256], *p;
    int in_trans = 0;
    while (fgets(line, sizeof line, f)) {
        if (line[0] == '#' || line[0] == '\n') continue;
        if (in_trans) {
            if (fa->nt < MAX && sscanf(line, "%63s %63s %63s", fa->t[fa->nt].from,
                                       fa->t[fa->nt].sym, fa->t[fa->nt].to) == 3)
                fa->nt++;
            continue;
        }
        p = strtok(line, " \t\r\n");
        if (!p) continue;
        if (strcmp(p, "initial") == 0) {
            p = strtok(NULL, " \t\r\n");
            if (p) strcpy(fa->initial, p);
        } else if (strcmp(p, "final") == 0) {
            while ((p = strtok(NULL, " \t\r\n")) && fa->nf < MAX)
                strcpy(fa->finals[fa->nf++], p);
        } else if (strcmp(p, "transitions") == 0) {
            in_trans = 1;
        }
    }
    fclose(f);
    return 0;
}

static int symbol_matches(const char *sym, char c) {
    if (strcmp(sym, "PRINTABLE") == 0)
        return c >= 32 && c <= 126;
    if (sym[0] == '[') {
        const char *p = sym + 1;
        int negate = 0, found = 0;
        if (*p == '^') {
            negate = 1;
            p++;
        }
        while (*p && *p != ']') {
            if (p[1] == '-' && p[2] && p[2] != ']') {
                if (c >= p[0] && c <= p[2]) found = 1;
                p += 3;
            } else {
                if (c == p[0]) found = 1;
                p++;
            }
        }
        return negate ? (!found && c >= 32 && c <= 126) : found;
    }
    return sym[0] == c && sym[1] == '\0';
}

static const char *next_state(const FA *fa, const char *state, char c) {
    for (int i = 0; i < fa->nt; i++)
        if (strcmp(fa->t[i].from, state) == 0 && symbol_matches(fa->t[i].sym, c))
            return fa->t[i].to;
    return NULL;
}

static int is_final(const FA *fa, const char *state) {
    for (int i = 0; i < fa->nf; i++)
        if (strcmp(fa->finals[i], state) == 0) return 1;
    return 0;
}

/* ---------- Program Internal Form, symbol table, errors ---------- */
typedef struct { char token[LEN]; int code, bucket, index; } PifEntry;

static PifEntry *pif;
static int pif_len, pif_cap;
static SymTab st;
static FILE *errf;
static FILE *faf;
static int error_count;

static void pif_add(const char *token, int code, int bucket, int index) {
    if (pif_len == pif_cap) {
        pif_cap = pif_cap ? pif_cap * 2 : 128;
        pif = realloc(pif, pif_cap * sizeof(PifEntry));
        if (!pif) {
            fprintf(stderr, "out of memory\n");
            exit(1);
        }
    }
    snprintf(pif[pif_len].token, LEN, "%s", token);
    pif[pif_len].code = code;
    pif[pif_len].bucket = bucket;
    pif[pif_len].index = index;
    pif_len++;
}

static void add_symbol(const char *kind, int code, StType type, const char *text) {
    StPos p = st_insert(&st, text, type);
    pif_add(kind, code, p.bucket, p.index);
}

static void error_at(int line, const char *msg, const char *s, int n) {
    error_count++;
    fprintf(errf, "Lexical error at line %d: %s '%.*s'\n", line, msg, n, s);
    fprintf(stderr, "Lexical error at line %d: %s '%.*s'\n", line, msg, n, s);
}

static void lex_error(const char *msg) {
    error_at(yylineno, msg, yytext, (int)yyleng);
}

static void fa_print(const char *name, const FA *fa) {
    fprintf(faf, "Automaton %s: initial state %s, final states", name, fa->initial);
    for (int i = 0; i < fa->nf; i++) fprintf(faf, " %s", fa->finals[i]);
    fprintf(faf, "\n");
    for (int i = 0; i < fa->nt; i++)
        fprintf(faf, "    %s --%s--> %s\n", fa->t[i].from, fa->t[i].sym, fa->t[i].to);
}

/* One line of the trace: the automaton, the lexeme, the states it went through
 * (repeated states are written as "q1 x3") and the result. */
static void fa_log(int line, const char *fa_name, const char *text, int n,
                   const char **path, const char *result) {
    char shown[40];
    if (n > 30) snprintf(shown, sizeof shown, "%.27s...", text);
    else        snprintf(shown, sizeof shown, "%.*s", n, text);
    fprintf(faf, "line %-3d  %-10s %-32s %s", line, fa_name, shown, path[0]);
    for (int i = 1; i <= n; ) {
        int j = i;
        while (j + 1 <= n && strcmp(path[j + 1], path[i]) == 0) j++;
        fprintf(faf, " -> %s", path[i]);
        if (j > i) fprintf(faf, " x%d", j - i + 1);
        i = j + 1;
    }
    fprintf(faf, "   %s\n", result);
}

static void fa_token(void);
%}

%%

[ \t\r\n]+                        { /* whitespace: ignored */ }
"//".*                            { /* comment: ignored */ }

[A-Za-z0-9\"]                     { fa_token(); }

[=!<>]=|"=>"|[=<>+\-*/%()\[\]{};,]   {
                                    int c = token_code(yytext);
                                    if (c >= 0)
                                        pif_add(yytext, c, -1, -1);
                                    else
                                        lex_error("symbol not in the token list:");
                                  }

.                                 { lex_error("invalid character:"); }

%%

/* Called when a token starts with a letter, a digit or a double quote.
 * The matching automaton (identifier, number or string) is run on the input,
 * character by character, and the longest accepted lexeme is kept. */
static void fa_token(void) {
    char buf[4096];
    const char *path[sizeof buf + 1];
    int len = 0, last = 0;
    int c = (unsigned char)yytext[0];
    int line = yylineno;
    const FA *fa = isalpha(c) ? &fa_id : isdigit(c) ? &fa_num : &fa_str;
    const char *fa_name = (fa == &fa_id) ? "identifier" : (fa == &fa_num) ? "number" : "string";
    const char *state = fa->initial;
    path[0] = state;

    for (;;) {
        const char *next = next_state(fa, state, (char)c);
        if (!next || len == (int)sizeof buf - 1) break;
        state = next;
        buf[len++] = (char)c;
        path[len] = state;
        if (is_final(fa, state)) last = len;
        c = input();
        if (c <= 0) {
            c = 0;
            break;
        }
    }

    if (len == 0) {
        error_at(line, "invalid character:", yytext, 1);
        return;
    }

    /* give back what was read but is not part of the longest accepted lexeme */
    int used = last ? last : len;
    if (c) unput(c);
    for (int i = len - 1; i >= used; i--)
        unput(buf[i]);
    buf[used] = '\0';

    if (fa == &fa_id) {
        int code = token_code(buf);
        char result[64];
        if (code >= 0) {
            snprintf(result, sizeof result, "accepted -> reserved word (code %d)", code);
            pif_add(buf, code, -1, -1);
        } else {
            snprintf(result, sizeof result, "accepted -> identifier");
            add_symbol("id", CODE_ID, ST_ID, buf);
        }
        fa_log(line, fa_name, buf, used, path, result);
    } else if (fa == &fa_num) {
        int next = input();
        if (next > 0) unput(next); else next = 0;
        int bad_word = (isalpha(next) || next == '_');
        int bad_zero = (buf[0] == '0' && isdigit(next));
        fa_log(line, fa_name, buf, used, path,
               (bad_word || bad_zero) ? "accepted prefix, then lexical error"
                                      : "accepted -> number constant");
        if (bad_word || bad_zero) {
            while ((c = input()) > 0 && used < (int)sizeof buf - 1 &&
                   (bad_word ? (isalnum(c) || c == '_') : isdigit(c)))
                buf[used++] = (char)c;
            if (c > 0) unput(c);
            error_at(line, bad_word ? "identifier cannot start with a digit:"
                                    : "number cannot have leading zeros:", buf, used);
        } else {
            add_symbol("const", CODE_CONST, ST_NUMBER, buf);
        }
    } else if (last == 0) {
        fa_log(line, fa_name, buf, used, path, "rejected (no final state reached) -> unterminated string");
        error_at(line, "unterminated string:", buf, used);
    } else {
        fa_log(line, fa_name, buf, used, path, "accepted -> string constant");
        add_symbol("const", CODE_CONST, ST_STRING, buf);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "usage: %s <source.meow>\n", argv[0]);
        return 1;
    }
    if (load_tokens("tokens.in") < 0 || read_fa("fa_identifier.in", &fa_id) < 0 ||
        read_fa("fa_number.in", &fa_num) < 0 || read_fa("fa_string.in", &fa_str) < 0)
        return 1;

    yyin = fopen(argv[1], "r");
    if (!yyin) {
        perror(argv[1]);
        return 1;
    }

    st_init(&st);
    errf = fopen("errors.out", "w");
    if (!errf) {
        perror("errors.out");
        return 1;
    }

    faf = fopen("fa.out", "w");
    if (!faf) {
        perror("fa.out");
        return 1;
    }
    fa_print("identifier", &fa_id);
    fa_print("number", &fa_num);
    fa_print("string", &fa_str);
    fprintf(faf, "\n");

    yylex();
    fclose(yyin);

    FILE *pf = fopen("pif.out", "w");
    FILE *sf = fopen("st.out", "w");
    if (!pf || !sf) {
        perror("output files");
        return 1;
    }

    fprintf(pf, "%-6s %-12s %s\n", "code", "token", "ST position");
    for (int i = 0; i < pif_len; i++) {
        if (pif[i].bucket < 0)
            fprintf(pf, "%-6d %-12s %s\n", pif[i].code, pif[i].token, "-");
        else
            fprintf(pf, "%-6d %-12s %d:%d\n", pif[i].code, pif[i].token,
                    pif[i].bucket, pif[i].index);
    }
    st_print(&st, sf);

    fprintf(errf, error_count ? "%d lexical error(s).\n" : "No lexical errors.\n", error_count);
    printf("%s: %d PIF entries, %d ST symbols, %d lexical error(s)\n",
           argv[1], pif_len, st.count, error_count);

    fclose(pf);
    fclose(sf);
    fclose(errf);
    fclose(faf);
    free(pif);
    st_free(&st);
    return error_count ? 2 : 0;
}
