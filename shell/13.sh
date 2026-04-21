#!/bin/bash
# Q13) Check whether number is even or odd

read n

if [ $((n%2)) -eq 0 ]
then echo "Even"
else echo "Odd"
fi