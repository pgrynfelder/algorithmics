g++ -O3 -static -std=c++17 -o nww.e nww.cpp
echo "Compilation finished"
for ((i=1; i < 40000; i++))
do 
    echo $i
    ./nww.e < test/in/nww$i.in > mine.out
    if diff -bwe mine.out test/out/nww$i.out
    then
        continue
    else
        echo "spitoliło się"
        echo $i
        break
    fi
done
echo "All tests ended succesfully"
