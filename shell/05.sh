#!/bin/bash
# Q5) Display system information:
# 1) Top 10 processes 2) Highest memory process 3) Current user 4) First 11 lines of file

ps aux --sort=-%cpu | head -10
ps aux --sort=-%mem | head -1
whoami
head -11 file.txt