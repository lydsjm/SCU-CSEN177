all: step2 step3 step4 step5

step2: step2.c
	gcc step2.c -o step2

step3: step3.c
	gcc step3.c -o step3

step4: step4.c
	gcc step4.c -o step4

step5: step5.c
	gcc step5.c -o step5 -lpthread

clean:
	rm -f step2 step3 step4 step5 *.out
