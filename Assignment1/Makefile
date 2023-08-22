q1.1: q1.1.c
	gcc q1.1.c -o q1.1

q1.2: q1.2.c
	gcc q1.2.c -o q1.2

run_p: q1.1 q1.2 
	echo "The output for the first part.\n\n"
	./q1.1
	
	echo "The output for the second part.\n\n"
	./q1.2  # Corrected executable name

clean:
	rm -f q1.1 q1.2

all: q1.1 q1.2 run_processes clean
