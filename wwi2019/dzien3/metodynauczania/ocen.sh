#!/bin/bash
while true
do
python3 gen.py > input
python3 metodynauczania.py < input > output1
./metodynauczania < input > output2
if diff -bwe output1 output2 > /dev/null
then
    continue
else
    echo "Wypitoliło"
    break
fi
done