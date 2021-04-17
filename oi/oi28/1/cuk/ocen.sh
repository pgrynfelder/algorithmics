#!/bin/bash
g++ -o3 -static -std=c++17 -o cuk.e cuk.cpp
echo "Compilation finished"
for ((i = 1; i < 80000; i++)); do
    echo $i
    ./cuk.e <tests/in/cuk$i.in >cuk.out
    if diff -b cuk.out tests/out/cuk$i.out; then
        continue
    else
        echo "spitoliło się na ${i}"
        exit
    fi
done

echo "All tests ended succesfully"
