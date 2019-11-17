g++ ukl.cpp -O3 -static -std=c++17 -o ukl.e -fsanitize=undefined
g++ checker.cpp -O3 -static -std=c++17 -o checker.e
g++ gen.cpp -O3 -static -std=c++17 -o gen.e 
g++ b.cpp -O3 -static -std=c++17 -o b.e 
echo "Compilation finished"
for ((i=1; i > -1; i++))
do
    echo $i
    # gen.e > 1.in
    cp 1.in kurwa.out
    ./ukl.e < 1.in >> kurwa.out
    # ./checker.e < 1.out > 2.out
    # if diff 2.out gituwa.out -bwe
    # then
    #     continue
    # else
    #     echo $i
    #     echo "ABORT"
    #     break
    # fi
    if diff kurwa.out xd.out
    then
        continue
    else
        echo $i
        echo "ABORT"
        break
    fi
done
echo "Tests ended"