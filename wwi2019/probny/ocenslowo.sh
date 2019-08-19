#!/bin/bash

for ((i = 1; i > -1; i++))
do
    echo $i > slowoi
    ./slowogen < slowoi > slowoin
    ./slowo < slowoin > slowoout
    ./slowobrut < slowoin > slowobrutout
    if diff slowoout slowobrutout > /dev/null
    then
        continue
    else
        echo "Nie działa"
        echo $i
        break 
    fi
done