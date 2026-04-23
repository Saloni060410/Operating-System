# sum of first n off numbers

read -p "enter number " n
sum=0
i=1
start=1

while [ $i -le $n ]
do
    sum=$((sum+start))
    i=$((i+1))
    start=$((start+2))
done

echo "$sum "