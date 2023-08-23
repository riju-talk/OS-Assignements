q1: q1.c
	gcc q1.c -o q1

q2: q2.c
	gcc q2.c -o q2

run_p: q1 q2 
	echo "The output for the first part.\n\n"
	./q1
	
	echo "The output for the second part.\n\n"
	./q2  # Corrected executable name

clean:
	rm -f q1 q2

all: q1 q2 run_processes clean
