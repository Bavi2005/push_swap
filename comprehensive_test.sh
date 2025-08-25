#!/bin/bash

echo "Comprehensive push_swap testing..."

# Test cases
test_cases=(
    "1"                   # Single number
    "1 2"                 # Already sorted
    "2 1"                 # Simple swap
    "1 2 3"               # Already sorted 3
    "3 2 1"               # Reverse sorted 3
    "2 1 3"               # Mixed 3
    "-1 -2 -3"            # Negative numbers
    "-3 -2 -1"            # Reverse negative
    "0 -1 1"              # With zero
    "2147483647 -2147483648" # Edge integers
    "5 2 8 1 9"           # Random 5
    "-5 2 -1 0 4"         # Mixed with negatives
    "1 3 2 4"             # 4 numbers
    "4 3 2 1"             # Reverse 4
)

for test_case in "${test_cases[@]}"; do
    echo "Testing: $test_case"
    ./push_swap $test_case | ./checker_linux $test_case
    if [ $? -eq 0 ]; then
        echo "✓ PASS"
    else
        echo "✗ FAIL"
    fi
    echo "---"
done

echo "Testing complete."
