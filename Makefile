q1: q1.c
	gcc q1.c -o q1
q2: q2.c
	gcc q2.c -o q2

run_prcesses: q1 21
	echo "The output for the first part."
	./q1
	
	echo "The output for the second part."
	./q2