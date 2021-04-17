#!/bin/bash
g++ -o3 -static -std=c++17 -o cuk.e cuk.cpp
g++ -o3 -static -std=c++17 -o dw.e dw.cpp
g++ -o3 -static -std=c++17 -o gen.e gen.cpp
echo "Compilation finished"
for i in {1..1000000}; do
    echo $i
    echo $i | ./gen.e >"in"
    ./cuk.e <"in" >cuk.out
    ./dw.e <"in" >dw.out
    if diff -b cuk.out dw.out; then
        continue
    else
        echo "spitoliło się"
        exit
    fi
done

echo "All tests ended succesfully"
