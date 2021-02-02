#!/bin/bash
g++ -o3 -static -std=c++17 a.cpp -o a.e
g++ -o3 -static -std=c++17 spo.cpp -o spo.e
g++ -o3 -static -std=c++17 gen.cpp -o gen.e
echo "Compiled"

for ((i = 1; i < 100; i++))
do
    echo $i > i.in
    ./gen.e < i.in > a.in
    
    ./spo.e < a.in > a.out
    ./wawszczak.e < a.in > b.out
    if diff a.out b.out > /dev/null
    then
        echo $i
    else
        echo "Nie działa na $i"
        break 
    fi
done