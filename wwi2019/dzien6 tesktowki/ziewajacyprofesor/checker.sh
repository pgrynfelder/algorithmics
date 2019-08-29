while true
do
    python3 gen.py > xd.in
    python3 brut.py < xd.in > brut.out
    ./ziewajacyprofesor3 < xd.in > wzo.out
    if diff -bwe brut.out wzo.out
    then
        continue
    else
        echo "ICHUJ"
        break
    fi
done