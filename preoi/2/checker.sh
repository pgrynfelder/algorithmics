#!/bin/bash
for ((i=0; i>-1; i++))
do
    echo $i
    python3 gen.py > in
    ./mocbrut.e < in > out1
    ./moc.e < in > out2
    if diff out1 out2
    then
        echo "ok"
    else
        echo "CRITICAL ERROR" 
        break
    fi
done