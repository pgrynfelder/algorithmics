for ((i=0; i > -1; i++))
do
    python3 gen.py > in
    python3 brut.py < in > out1
    ./ple < in > out2
    if diff out1 out2
    then
        echo $i
        echo ok
    else
        echo $i
        echo aufgefickt
        break
    fi
done
