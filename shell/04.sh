#!/bin/bash
# Q4) Check whether a person is eligible to vote

read -p "Enter age: " age

if [ $age -ge 18 ]
then echo "Eligible"
else echo "Not Eligible"
fi