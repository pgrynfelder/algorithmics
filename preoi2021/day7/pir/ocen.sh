#!/bin/bash
g++ -o3 -static -std=c++17 pir.cpp -o pir.e
g++ -o3 -static -std=c++17 brut.cpp -o brut.e
g++ -o3 -static -std=c++17 gen.cpp -o gen.e
echo "Compiled"

for ((i = 1; i > -1; i++))
do
    echo $i > pir.i
    ./gen.e < pir.i > pir.in
    
    ./pir.e < pir.in > pir.out
    ./brut.e < pir.in > brut.out
    if diff pir.out brut.out > /dev/null
    then
        echo $i
    else
        echo "Nie działa na $i"
        break 
    fi
done