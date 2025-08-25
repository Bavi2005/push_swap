#!/bin/bash

echo "Testing push_swap implementation..."

# Test 1: Simple case (2 numbers)
echo "Test 1: 2 numbers"
./push_swap 2 1 | ./checker_linux 2 1
echo "Exit code: $?"

# Test 2: Negative numbers
echo "Test 2: Negative numbers"
./push_swap -1 -2 -3 | ./checker_linux -1 -2 -3
echo "Exit code: $?"

# Test 3: Mixed positive and negative
echo "Test 3: Mixed numbers"
./push_swap -5 2 -1 0 4 | ./checker_linux -5 2 -1 0 4
echo "Exit code: $?"

# Test 4: Already sorted
echo "Test 4: Already sorted"
./push_swap 1 2 3 | ./checker_linux 1 2 3
echo "Exit code: $?"

echo "Testing complete."
