#include <stdlib.h>
#include <string.h>
#include "symtab.h"

static char *copy_text(const char *s) {
    char *p = malloc(strlen(s) + 1);
    if (!p) {
        fprintf(stderr, "out of memory\n");
        exit(1);
    }
    strcpy(p, s);
    return p;
}

static const char *type_name(StType t) {
    switch (t) {
        case ST_ID:     return "identifier";
        case ST_NUMBER: return "number";
        default:        return "string";
    }
}

void st_init(SymTab *st) {
    for (int i = 0; i < ST_SIZE; i++)
        st->buckets[i] = NULL;
    st->count = 0;
}

/* polynomial hash: h = h * 31 + c, reduced modulo the table size */
unsigned st_hash(const char *text) {
    unsigned long h = 0;
    for (const char *p = text; *p; p++)
        h = h * 31 + (unsigned char)*p;
    return (unsigned)(h % ST_SIZE);
}

/* Returns the position of text; inserts it at the end of its chain if absent. */
StPos st_insert(SymTab *st, const char *text, StType type) {
    StPos pos;
    pos.bucket = (int)st_hash(text);
    pos.index = 0;

    StEntry *cur = st->buckets[pos.bucket];
    StEntry *last = NULL;
    while (cur) {
        if (strcmp(cur->text, text) == 0)
            return pos;
        last = cur;
        cur = cur->next;
        pos.index++;
    }

    StEntry *e = malloc(sizeof(StEntry));
    if (!e) {
        fprintf(stderr, "out of memory\n");
        exit(1);
    }
    e->text = copy_text(text);
    e->type = type;
    e->next = NULL;
    if (last)
        last->next = e;
    else
        st->buckets[pos.bucket] = e;
    st->count++;
    return pos;
}

/* Returns the position of text, or bucket = -1 if it is not in the table. */
StPos st_lookup(const SymTab *st, const char *text) {
    StPos pos;
    pos.bucket = (int)st_hash(text);
    pos.index = 0;

    for (StEntry *cur = st->buckets[pos.bucket]; cur; cur = cur->next) {
        if (strcmp(cur->text, text) == 0)
            return pos;
        pos.index++;
    }
    pos.bucket = -1;
    pos.index = -1;
    return pos;
}

void st_print(const SymTab *st, FILE *out) {
    fprintf(out, "%-10s %-12s %s\n", "position", "type", "symbol");
    for (int b = 0; b < ST_SIZE; b++) {
        int idx = 0;
        for (StEntry *cur = st->buckets[b]; cur; cur = cur->next, idx++) {
            char pos[24];
            snprintf(pos, sizeof pos, "%d:%d", b, idx);
            fprintf(out, "%-10s %-12s %s\n", pos, type_name(cur->type), cur->text);
        }
    }
}

void st_free(SymTab *st) {
    for (int b = 0; b < ST_SIZE; b++) {
        StEntry *cur = st->buckets[b];
        while (cur) {
            StEntry *next = cur->next;
            free(cur->text);
            free(cur);
            cur = next;
        }
        st->buckets[b] = NULL;
    }
    st->count = 0;
}
