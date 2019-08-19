#!/bin/bash
for ((i = 1; i > -1; i++))
do
    echo $i > drzewo.i
    ./testowaniedrzewo < drzewoi > drzewoin
    ./drzewo < drzewoin > drzewoout
    if diff drzewoout dzialaout > /dev/null
    then
        continue
    else
        echo "Nie działa"
        echo $i
        break 
    fi
done