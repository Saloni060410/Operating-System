#!/bin/bash
# Q15) Find sum of first n numbers

read n
sum=0

for ((i=1;i<=n;i++))
do
    sum=$((sum+i))
done

echo "Sum = $sum"
