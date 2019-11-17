g++ ukl.cpp -O3 -static -std=c++17 -o ukl.e 
g++ checker.cpp -O3 -static -std=c++17 -o checker.e
g++ gen.cpp -O3 -static -std=c++17 -o gen.e 
g++ b.cpp -O3 -static -std=c++17 -o b.e 
echo "Compilation finished"
for ((i=1; i > -1; i++))
do
    echo $i
    python3 gen.py > 1.in
    # gen.e > 1.in
    cp 1.in 1.out
    ./ukl.e < 1.in >> 1.out
    # ./checker.e < 1.out > 2.out
    ./b.e < 1.out > 3.out
    # if diff 2.out gituwa.out -bwe
    # then
    #     continue
    # else
    #     echo $i
    #     echo "ABORT"
    #     break
    # fi
    if diff 3.out ok.out
    then
        continue
    else
        echo $i
        echo "ABORT"
        break
    fi
done
echo "Tests ended"