# Name: Lydia Myla
# Date: 11/12/24
# Title: Lab 8 - Step 6 Part 1
# Description: Bash script to test page replacement algorithms with detailed output

#!/bin/bash
# Compile the C programs
make;

TOTAL_REQUESTS=10000

echo "---------- FIFO ----------"
cat testInput.txt | ./fifo 10
echo "---------- End FIFO ----------"
echo

echo "---------- LRU ----------"
cat testInput.txt | ./lru 10
echo "---------- End LRU ----------"
echo

echo "---------- Second Chance ----------"
cat testInput.txt | ./sec_chance 10
echo "---------- End Second Chance ----------"
echo

# Run detailed tests on accesses.txt with multiple cache sizes
echo "FIFO 10K Test with cache sizes = 10, 50, 100, 250, 500"
for size in 10 50 100 250 500; do
    faults=$(cat accesses.txt | ./fifo "$size" | wc -l)
    miss_rate=$(echo "scale=4; $faults / $TOTAL_REQUESTS" | bc)
    echo "Cache size = $size, miss-rate = $faults / $TOTAL_REQUESTS = $miss_rate"
done
echo

echo "LRU 10K Test with cache sizes = 10, 50, 100, 250, 500"
for size in 10 50 100 250 500; do
    faults=$(cat accesses.txt | ./lru "$size" | wc -l)
    miss_rate=$(echo "scale=4; $faults / $TOTAL_REQUESTS" | bc)
    echo "Cache size = $size, miss-rate = $faults / $TOTAL_REQUESTS = $miss_rate"
done
echo

echo "Second Chance 10K Test with cache sizes = 10, 50, 100, 250, 500"
for size in 10 50 100 250 500; do
    faults=$(cat accesses.txt | ./sec_chance "$size" | wc -l)
    miss_rate=$(echo "scale=4; $faults / $TOTAL_REQUESTS" | bc)
    echo "Cache size = $size, miss-rate = $faults / $TOTAL_REQUESTS = $miss_rate"
done
echo

# Clean up compiled files
make clean;
echo
