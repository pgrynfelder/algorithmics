#!/bin/bash

for ((i = 1; i>0; i++))
do 
    echo $i > wormsi
    ./wormsgen < wormsi > wormsin
    ./wormsy2 < wormsin > worms2out
    ./wormsy6 < wormsin > worms3out
    if diff -bew worms3out worms2out > /dev/null
    then
        continue
    else
        echo "i chuj"
        echo $i
        break
    fi
done