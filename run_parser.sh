#!/bin/bash
# Builds the parser (bison + flex) and runs it on the test programs.
# Results are saved as <name>_productions.out, <name>_pif.out and <name>_st.out

cd "$(dirname "$0")" || exit 1
bison -Wall -d -o parser.tab.c parser.y || { echo "bison failed"; exit 1; }
flex lexer.l                            || { echo "flex failed"; exit 1; }
gcc -Wall -Wextra lex.yy.c parser.tab.c symtab.c -o meowparse || { echo "gcc failed"; exit 1; }

for f in p1 p2; do
    echo "== $f.meow: scanner + parser =="
    ./meowparse $f.meow
    cp productions.out "${f}_productions.out"
    cp pif.out         "${f}_pif.out"
    cp st.out          "${f}_st.out"

    echo "== $f: parser reading the PIF =="
    ./meowparse --pif "${f}_pif.out" "${f}_st.out"
    if cmp -s productions.out "${f}_productions.out"; then
        echo "same productions as with the scanner"
    else
        echo "DIFFERENT productions"
    fi
    echo
done

for f in syntax1 syntax2 syntax3 syntax4; do
    echo "== $f.meow (syntax error expected) =="
    ./meowparse $f.meow
    echo
done
