#!/bin/bash

echo "Działa dobrze." > drzewobrut
for ((i = 1; i > -1; i++))
do
    echo $i > drzewoi
    ./testowaniedrzewo < drzewoi > drzewoin
    ./drzewo < drzewoin > drzewoout
    if diff drzewoout drzewobrut > /dev/null
    then
        continue
    else
        echo "Nie działa"
        echo $i
        break 
    fi
done