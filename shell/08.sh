#!/bin/bash
# Q8) Perform directory and file operations
# Create a directory named OS_Practical. Inside this directory, create three files:
# file1.txt ,file2.txt and file3.txt. Copy file1.txt to a new file named file1_backup.txt.
# Move file2.txt to the Backup directory. Rename file3.txt to updated_file3.txt using the
# mv command. Remove the entire Backup directory along with its contents.

mkdir OS_Practical
cd OS_Practical

touch file1.txt file2.txt file3.txt
cp file1.txt file1_backup.txt

mkdir Backup
mv file2.txt Backup/

mv file3.txt updated_file3.txt

rm -r Backup