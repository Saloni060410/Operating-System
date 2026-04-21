#!/bin/bash
# Q) Write a shell program to create two customer files storing:
# Custid, Custname, City, Balance and perform:
# a) Concatenate into 3rd file and display
# b) Count contents of the file

# Create first customer file
echo "Enter details for Customer File 1"
read -p "CustID: " id1
read -p "Name: " name1
read -p "City: " city1
read -p "Balance: " bal1

echo "$id1 $name1 $city1 $bal1" > cust1.txt

# Create second customer file
echo "Enter details for Customer File 2"
read -p "CustID: " id2
read -p "Name: " name2
read -p "City: " city2
read -p "Balance: " bal2

echo "$id2 $name2 $city2 $bal2" > cust2.txt

# a) Concatenate into third file
cat cust1.txt cust2.txt > cust3.txt

echo "Contents of Customer File 3:"
cat cust3.txt

# b) Count contents (lines, words, characters)
echo "Count of contents in cust3.txt:"
wc cust3.txt