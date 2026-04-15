#!/bin/bash
# 
# testing.sh
# Megan Lu
# COSC050, 26S
#
# Description: test cases for chill.c

# Zero arguments
./chill

# One argument tests:
# In range
./chill 32
# Lower boundary
./chill -99
# Upper boundary
./chill 50
# Out of range (below)
./chill -100
# Out of range (above)
./chill 51

# Two arguments tests:
# Both in range
./chill 32.5 10
# Velocity lower boundary
./chill 6.02 0.5
# Only velocity out of range
./chill 3.14 0
# Only temperature out of range
./chill 55 1.5
# Both out of range
./chill 67 -3

# More than two arguments
./chill 1 2 3

exit 0
