#!/bin/bash
# Q3) Compute Fibonacci series using while loop

read -p "Enter n: " n
a=0
b=1
i=1

while [ $i -le $n ]
do
    echo -n "$a "
    c=$((a + b))
    a=$b
    b=$c
    i=$((i+1))
done