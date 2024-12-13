#!/bin/bash
for file in file1.bin file2.bin file3.bin file4.bin
do
	for buffer in 100 1000 10000 100000
	do
		echo "Step4 $file $buffer"
		time ./step4 $file $buffer
		rm copy.out
		echo " "
	done
done