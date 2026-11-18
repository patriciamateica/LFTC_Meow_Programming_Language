#!/bin/bash
# Builds the flex lexer (with the finite automata integrated) and runs it on the test programs.
# The results of each run are saved as <name>_pif.out, <name>_st.out, <name>_errors.out, <name>_fa.out

cd "$(dirname "$0")" || exit 1
flex lexer.l || { echo "flex failed"; exit 1; }
gcc -Wall -Wextra lex.yy.c symtab.c -o meowlex || { echo "gcc failed"; exit 1; }

for f in p1 p2 errors edge; do
    echo "== $f.meow =="
    ./meowlex $f.meow
    cp pif.out    "${f}_pif.out"
    cp st.out     "${f}_st.out"
    cp errors.out "${f}_errors.out"
    cp fa.out     "${f}_fa.out"
    echo
done
