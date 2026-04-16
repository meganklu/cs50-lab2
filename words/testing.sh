#!/bin/bash
# 
# testing.sh
# Megan Lu
# COSC050, 26S
#
# Description: test cases for words.c

# Zero arguments
./words < "test.txt"

# Multiple arguments
./words "test.txt"
./words "test.txt" "empty.txt" "words.c"

# Using special filename - and files
echo "this is the stdin" | ./words "test.txt" - "test.txt" - 

# Unreadable file first
./words "nonexistent.txt" "test.txt"

# Unreadable file in list
./words "test.txt" "nonexistent.txt"

# No words in any file
echo "!!!" | ./words "empty.txt" "empty.txt" "empty.txt" -
