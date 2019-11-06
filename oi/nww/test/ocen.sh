for ((i=1; i < 5; i++))
do 
    ./nww < in/nww$i.in > output
    if diff -bwe output "out/nww"$i".out" > /dev/null
    then
        continue
    else
        echo "spitoliło się"
        echo $i
        break
    fi
done