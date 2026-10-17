#ifndef SYMTAB_H
#define SYMTAB_H

#include <stdio.h>

/* Symbol table: hash table with separate chaining.
 * Holds identifiers and constants (numbers and strings).
 * A position is the pair (bucket, index in that bucket's chain). */

#define ST_SIZE 31

typedef enum { ST_ID, ST_NUMBER, ST_STRING } StType;

typedef struct StEntry {
    char *text;
    StType type;
    struct StEntry *next;
} StEntry;

typedef struct {
    int bucket;   /* -1 means "not found" */
    int index;
} StPos;

typedef struct {
    StEntry *buckets[ST_SIZE];
    int count;
} SymTab;

void     st_init(SymTab *st);
unsigned st_hash(const char *text);
StPos    st_insert(SymTab *st, const char *text, StType type);
StPos    st_lookup(const SymTab *st, const char *text);
void     st_print(const SymTab *st, FILE *out);
void     st_free(SymTab *st);

#endif
