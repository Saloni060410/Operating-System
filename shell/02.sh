#!/bin/bash
# Q2) Check whether a 3-digit number is Armstrong or not

read -p "Enter number: " n
sum=0
temp=$n

while [ $temp -gt 0 ]
do
    d=$((temp % 10))
    sum=$((sum + d*d*d))
    temp=$((temp / 10))
done

if [ $sum -eq $n ]
then echo "Armstrong"
else echo "Not Armstrong"
fi