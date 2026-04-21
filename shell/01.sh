#!/bin/bash
# Q1) Create two files with names and perform:
# a) Concatenate b) Ascending sort c) Descending sort d) Clear contents

echo -e "A\nB\nC\nD\nE" > file1.txt
echo -e "F\nG\nH\nI\nJ" > file2.txt

echo "Concatenation:"
cat file1.txt file2.txt

echo "Ascending Order:"
sort file1.txt file2.txt

echo "Descending Order:"
sort -r file1.txt file2.txt

echo "Clearing files..."
> file1.txt
> file2.txt