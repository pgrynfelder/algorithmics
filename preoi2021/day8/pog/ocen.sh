#!/bin/bash
g++ -o3 -static -std=c++17 a.cpp -o a.e
g++ -o3 -static -std=c++17 brut.cpp -o brut.e
g++ -o3 -static -std=c++17 gen.cpp -o gen.e
echo "Compiled"

for ((i = 1; i < 100000000; i++))
do
    echo $i > i.in
    ./gen.e < i.in > a.in
    
    ./a.e < a.in > a.out
    ./brut.e < a.in > brut.out
    if diff a.out brut.out > /dev/null
    then
        echo $i
    else
        echo "Nie działa na $i"
        break 
    fi
done