#!/bin/bash
ZAD="tab"

g++ -O3 -static -std=c++17 -o ${ZAD}.e ${ZAD}.cpp
echo "Compilation finished"
for ((i = 0; i < 5000; i++)); do
    echo $i
    ./${ZAD}.e < tests/subtask6/in/tab${i}.in > ${ZAD}.out
    if diff -b tests/subtask6/out/tab${i}.out ${ZAD}.out; then
        continue
    else
        echo "spitoliło się na i: ${i}"
        exit
    fi
done

echo "All tests ended succesfully"
