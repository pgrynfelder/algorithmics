g++ -O3 -static -o ukl.e ukl.cpp
g++ -O3 -static -o checker.e checker.cpp
echo "Compilation finished"
for ((i=1; i < 1000; i++))
do
    python3 gen.py > 1.in
    cp 1.in 1.out
    ./ukl.e < 1.in >> 1.out
    ./checker.e < 1.out > 2.out
    if diff 2.out gituwa.out -b
    then
        continue
    else
        echo $i
        echo "ABORT"
        break
    fi
done
echo "Tests ended successfully"