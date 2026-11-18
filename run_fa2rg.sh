#!/bin/bash
# Builds fa2rg, runs it on the three automata and compares the result
# with the hand-written grammars (rg_*.in, comment lines ignored).

cd "$(dirname "$0")" || exit 1
gcc -Wall -Wextra fa2rg.c -o fa2rg || { echo "build failed"; exit 1; }

for n in identifier number string; do
    echo "== $n =="
    ./fa2rg fa_$n.in > out_$n.txt 2> trace_$n.txt
    echo "-- trace"
    cat trace_$n.txt
    echo "-- grammar"
    cat out_$n.txt
    if diff <(grep -v '^#' rg_$n.in) out_$n.txt > /dev/null; then
        echo "=> same as rg_$n.in"
    else
        echo "=> DIFFERENT from rg_$n.in"
    fi
    echo
done

echo "== strings tested with the automata =="
./fa2rg fa_identifier.in x1 box_2 2x _a 2>/dev/null | grep '^test'
./fa2rg fa_number.in 0 42 007 12a 2>/dev/null | grep '^test'
./fa2rg fa_string.in '"hi"' '"Purr..."' '""' '"abc' 2>/dev/null | grep '^test'
