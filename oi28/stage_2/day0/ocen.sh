#!/bin/bash
g++ -std=c++17 -o3 -s -lm pro.cpp -o pro.e
g++ -std=c++17 -o3 -s -lm check.cpp -o check.e
g++ -std=c++17 -o3 -s -lm gen.cpp -o gen.e

for ((i = 1; i < 100000000; i++))
do
    echo $i >i.in
    ./gen.e <i.in >k.in
    ./pro.e <k.in >pro.out
    ./check.e <pro.out >check.out
    if diff -w check.out k.in; then
        echo $i
    else
        echo "$i broke"
        break
    fi

done
