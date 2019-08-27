for ((i=0; i > -1; i++))
do
    python3 gruszkigen.py > input
    python3 gruszkibrut.py < input > output1
    ./gruszki < input > output2
    if diff -bwe output1 output2 > /dev/null
    then
        continue
    else
        echo "chuj"
        break
    fi

done