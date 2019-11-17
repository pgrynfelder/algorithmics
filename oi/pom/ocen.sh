g++ -O3 -static -std=c++17 -o nww.e nww.cpp
echo "Compilation finished"
for ((i=0; i < 2000; i++))
do 
    echo $i
    ./a.out < test/in/pom$i.in > mine.out
    if diff -bwe mine.out test/out/pom$i.out
    then
        continue
    else
        echo "spitoliło się"
        echo $i
        break
    fi
done
echo "All tests ended succesfully"
