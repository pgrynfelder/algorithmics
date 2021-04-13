#!/bin/bash
g++ -o3 -static -std=c++17 -o lic.e lic.cpp
g++ -o3 -static -std=c++17 -o dw.e dw.cpp
g++ -o3 -static -std=c++17 -o gen.e gen.cpp
echo "Compilation finished"
for i in {1..1000000}; do
    echo $i
    echo $i | ./gen.e >"in"
    ./lic.e <"in" >lic.out
    ./dw.e <"in" >dw.out
    if diff -b lic.out dw.out; then
        continue
    else
        echo "spitoliło się"
        exit
    fi
done

echo "All tests ended succesfully"
