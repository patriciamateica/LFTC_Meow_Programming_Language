%option noyywrap yylineno nounput noinput

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symtab.h"

/* Token codes: 0 = identifier, 1 = constant,
 * every token read from tokens.in gets 2, 3, 4, ... in file order. */
#define CODE_ID    0
#define CODE_CONST 1

/* ---------- Token list (read from tokens.in) ---------- */
typedef struct {
    char *text;
    int code;
} Token;

static Token *tokens = NULL;
static int tok_len = 0, tok_cap = 0;

/* ---------- Program Internal Form ---------- */
typedef struct {
    char *token;     /* token text, or "id" / "const" */
    int code;
    int bucket;      /* ST position, or -1 when the token has none */
    int index;
} PifEntry;

static PifEntry *pif = NULL;
static int pif_len = 0, pif_cap = 0;

static SymTab st;
static FILE *errf = NULL;
static int error_count = 0;

static char *dup_text(const char *s) {
    char *p = malloc(strlen(s) + 1);
    if (!p) { fprintf(stderr, "out of memory\n"); exit(1); }
    strcpy(p, s);
    return p;
}

/* Reads the token list: one token per line; blank lines and lines
 * starting with '#' are ignored. Returns the number of tokens, or -1. */
static int load_tokens(const char *path) {
    FILE *f = fopen(path, "r");
    if (!f) return -1;

    char line[256];
    while (fgets(line, sizeof line, f)) {
        size_t n = strlen(line);
        while (n > 0 && (line[n-1] == '\n' || line[n-1] == '\r' ||
                         line[n-1] == ' '  || line[n-1] == '\t'))
            line[--n] = '\0';
        char *p = line;
        while (*p == ' ' || *p == '\t') p++;
        if (*p == '\0' || *p == '#') continue;

        if (tok_len == tok_cap) {
            tok_cap = tok_cap ? tok_cap * 2 : 64;
            tokens = realloc(tokens, tok_cap * sizeof(Token));
            if (!tokens) { fprintf(stderr, "out of memory\n"); exit(1); }
        }
        tokens[tok_len].text = dup_text(p);
        tokens[tok_len].code = tok_len + 2;
        tok_len++;
    }
    fclose(f);
    return tok_len;
}

/* Returns the code of text if it is in the token list, otherwise -1. */
static int token_code(const char *text) {
    for (int i = 0; i < tok_len; i++)
        if (strcmp(tokens[i].text, text) == 0)
            return tokens[i].code;
    return -1;
}

static void pif_add(const char *token, int code, int bucket, int index) {
    if (pif_len == pif_cap) {
        pif_cap = pif_cap ? pif_cap * 2 : 128;
        pif = realloc(pif, pif_cap * sizeof(PifEntry));
        if (!pif) { fprintf(stderr, "out of memory\n"); exit(1); }
    }
    pif[pif_len].token = dup_text(token);
    pif[pif_len].code = code;
    pif[pif_len].bucket = bucket;
    pif[pif_len].index = index;
    pif_len++;
}

static void add_symbol(const char *kind, int code, StType type) {
    StPos p = st_insert(&st, yytext, type);
    pif_add(kind, code, p.bucket, p.index);
}

static void lex_error(const char *msg) {
    error_count++;
    fprintf(errf, "Lexical error at line %d: %s '%s'\n", yylineno, msg, yytext);
    fprintf(stderr, "Lexical error at line %d: %s '%s'\n", yylineno, msg, yytext);
}
%}

LETTER   [A-Za-z]
DIGIT    [0-9]

%%

[ \t\r\n]+                        { /* whitespace: ignored */ }
"//".*                            { /* comment: ignored */ }

{LETTER}({LETTER}|{DIGIT}|_)*     {
                                    int c = token_code(yytext);
                                    if (c >= 0)
                                        pif_add(yytext, c, -1, -1);        /* reserved word */
                                    else
                                        add_symbol("id", CODE_ID, ST_ID);  /* identifier */
                                  }

0|[1-9]{DIGIT}*                   { add_symbol("const", CODE_CONST, ST_NUMBER); }
\"[^\"\n]*\"                      { add_symbol("const", CODE_CONST, ST_STRING); }

[=!<>]=|"=>"|[=<>+\-*/%()\[\]{};,]   {
                                    int c = token_code(yytext);
                                    if (c >= 0)
                                        pif_add(yytext, c, -1, -1);        /* operator / separator */
                                    else
                                        lex_error("symbol not in the token list:");
                                  }

{DIGIT}+({LETTER}|_)({LETTER}|{DIGIT}|_)*   { lex_error("identifier cannot start with a digit:"); }
0{DIGIT}+                         { lex_error("number cannot have leading zeros:"); }
\"[^\"\n]*                        { lex_error("unterminated string:"); }
.                                 { lex_error("invalid character:"); }

%%

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "usage: %s <source.meow> [tokens.in]\n", argv[0]);
        return 1;
    }
    const char *token_path = (argc > 2) ? argv[2] : "tokens.in";

    if (load_tokens(token_path) < 0) {
        perror(token_path);
        return 1;
    }

    yyin = fopen(argv[1], "r");
    if (!yyin) {
        perror(argv[1]);
        return 1;
    }

    st_init(&st);
    errf = fopen("errors.out", "w");
    if (!errf) { perror("errors.out"); return 1; }

    yylex();
    fclose(yyin);

    FILE *pf = fopen("pif.out", "w");
    FILE *sf = fopen("st.out", "w");
    if (!pf || !sf) { perror("output files"); return 1; }

    fprintf(pf, "%-6s %-12s %s\n", "code", "token", "ST position");
    for (int i = 0; i < pif_len; i++) {
        if (pif[i].bucket < 0)
            fprintf(pf, "%-6d %-12s %s\n", pif[i].code, pif[i].token, "-");
        else
            fprintf(pf, "%-6d %-12s %d:%d\n", pif[i].code, pif[i].token,
                    pif[i].bucket, pif[i].index);
    }
    st_print(&st, sf);

    if (error_count == 0)
        fprintf(errf, "No lexical errors.\n");
    else
        fprintf(errf, "%d lexical error(s).\n", error_count);

    printf("%s (tokens from %s: %d): %d PIF entries, %d ST symbols, %d lexical error(s)\n",
           argv[1], token_path, tok_len, pif_len, st.count, error_count);

    fclose(pf);
    fclose(sf);
    fclose(errf);
    for (int i = 0; i < pif_len; i++)
        free(pif[i].token);
    free(pif);
    for (int i = 0; i < tok_len; i++)
        free(tokens[i].text);
    free(tokens);
    st_free(&st);
    return error_count ? 2 : 0;
}
