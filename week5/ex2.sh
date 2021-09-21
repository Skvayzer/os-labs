if [ ! -f num.txt ]; then
echo 0 > num.txt
fi


counter=0
#for i in {1..100}; do

#done

while [ $counter -lt 10 ]; do
    if [ ! -f num.lock ]; then
        ln num.txt num.lock
    else
        #append
        rm num.lock
    fi
#     i=$(tail -1 num.txt)
    counter=$(( counter+1 ))
    echo $counter >> num.txt
done


