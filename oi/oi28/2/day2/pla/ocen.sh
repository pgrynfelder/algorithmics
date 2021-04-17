#!/bin/bash
g++ -o3 -lm -s -std=c++17 pla.cpp -o a.e

for t in tests/*.in; do
    echo $t
    o=${t%.in}.out
    diff -b $o <(./a.e <$t) >/dev/null || break
done
