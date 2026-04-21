#!/bin/bash
# Q) Write a shell program to create two employee files storing:
# Empid, Empname, Salary, Designation and perform:
# a) Concatenate into 3rd file and display
# b) Count contents of the file

# Create first employee file
echo "Enter details for Employee File 1"
read -p "EmpID: " id1
read -p "Name: " name1
read -p "Salary: " sal1
read -p "Designation: " des1

echo "$id1 $name1 $sal1 $des1" > emp1.txt

# Create second employee file
echo "Enter details for Employee File 2"
read -p "EmpID: " id2
read -p "Name: " name2
read -p "Salary: " sal2
read -p "Designation: " des2

echo "$id2 $name2 $sal2 $des2" > emp2.txt

# a) Concatenate into third file
cat emp1.txt emp2.txt > emp3.txt

echo "Contents of Employee File 3:"
cat emp3.txt

# b) Count contents (lines, words, characters)
echo "Count of contents in emp3.txt:"
wc emp3.txt