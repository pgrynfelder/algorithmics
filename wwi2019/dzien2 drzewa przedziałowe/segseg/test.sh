#!/bin/bash

for ((i = 1; i>0; i++))
do
    echo $i > "i"
    ./testgen < "i" > "in"
    ./segseg < "in" > out1
    ./segbrut < "in" > out2
    if diff -bew out1 out2 > /dev/null
    then
        continue
    else
        echo "i chuj"
        echo $i
        break
    fi
done