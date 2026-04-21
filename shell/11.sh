#!/bin/bash
# Q11) Display grade based on percentage

read p

if [ $p -ge 75 ]
then echo "Distinction"
elif [ $p -ge 60 ]
then echo "First Class"
elif [ $p -ge 50 ]
then echo "Second Class"
else echo "Fail"
fi