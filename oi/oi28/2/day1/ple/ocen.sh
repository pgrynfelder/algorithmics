#!/bin/bash
g++ -std=c++17 -o3 -s -lm ple3.cpp -o a.e
g++ -std=c++17 -o3 -s -lm brut.cpp -o b.e
g++ -std=c++17 -o3 -s -lm gen.cpp -o gen.e

for ((i = 1; i < 100000000; i++)); do
    echo $i >i.in
    ./gen.e <i.in >a.in
    ./a.e <a.in >a.out
    ./b.e <a.in >b.out
    if diff -w a.out b.out; then
        echo $i
    else
        echo "$i broke"
        break
    fi

done
