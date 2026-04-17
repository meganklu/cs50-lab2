#!/bin/bash
# 
# testing.sh
# Megan Lu
# COSC050, 26S
#
# Description: test cases for histo.c

# First example
# Contains negative integers and different spacing (space, tab, newline)
echo -e "3 -4 5 1 7 0\n8 0 15 12 3 5\n3 3 3 3\n\t-5\t 3" | ./histo

# Second example
# Contains numbers outside the original range
echo -e "3 -4 5 1 7 0\n8 0 15 12 3 5\n18\n19 20 30 7 12\n50\n34\n32\n19\n44" | ./histo

# Third example
# Repeat doubling of bin size
echo 150 | ./histo

# Fourth example
# Contains numbers at the boundary of the current size (16) and outside the range
echo {1..16} 150 | ./histo

# Extra tests

# Boundaries of range 
echo {0..15} | ./histo
# Doubling bin size
echo {0..16} | ./histo
# Spacing of [low:high] range
echo 0 10 100 1000 | ./histo
echo 0 10 100 10000 | ./histo
# Normal distribution data (file)
./histo < random.txt
