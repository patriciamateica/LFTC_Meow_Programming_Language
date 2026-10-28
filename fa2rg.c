#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LEN 64
#define MAX 128

typedef struct { char from[LEN], sym[LEN], to[LEN]; } Trans;

static Trans t[MAX];
static int nt;
static char finals[MAX][LEN];
static int nf;
static char initial[LEN];

static int is_final(const char *s) {
    for (int i = 0; i < nf; i++)
        if (strcmp(finals[i], s) == 0) return 1;
    return 0;
}

static int has_out(const char *s) {
    for (int i = 0; i < nt; i++)
        if (strcmp(t[i].from, s) == 0) return 1;
    return 0;
}

static void upper(char *s) {
    for (; *s; s++) *s = (char)toupper((unsigned char)*s);
}

static void read_fa(FILE *f) {
    char line[256], *p;
    int in_trans = 0;
    while (fgets(line, sizeof line, f)) {
        if (line[0] == '#' || line[0] == '\n') continue;
        if (in_trans) {
            sscanf(line, "%63s %63s %63s", t[nt].from, t[nt].sym, t[nt].to);
            nt++;
            continue;
        }
        p = strtok(line, " \t\r\n");
        if (!p) continue;
        if (strcmp(p, "initial") == 0)
            strcpy(initial, strtok(NULL, " \t\r\n"));
        else if (strcmp(p, "final") == 0)
            while ((p = strtok(NULL, " \t\r\n"))) strcpy(finals[nf++], p);
        else if (strcmp(p, "transitions") == 0)
            in_trans = 1;
    }
}

static void fa_to_rg(void) {
    char P[LEN], Q[LEN];

    strcpy(P, initial);
    upper(P);
    printf("start %s\nproductions\n", P);
    if (is_final(initial))
        printf("%s -> epsilon\n", P);

    for (int i = 0; i < nt; i++) {
        strcpy(P, t[i].from);
        upper(P);
        strcpy(Q, t[i].to);
        upper(Q);
        if (has_out(t[i].to))
            printf("%s -> %s %s\n", P, t[i].sym, Q);
        if (is_final(t[i].to))
            printf("%s -> %s\n", P, t[i].sym);
    }
}

int main(int argc, char **argv) {
    FILE *f = (argc > 1) ? fopen(argv[1], "r") : NULL;
    if (!f) {
        fprintf(stderr, "usage: %s <fa_file>\n", argv[0]);
        return 1;
    }
    read_fa(f);
    fclose(f);
    fa_to_rg();
    return 0;
}