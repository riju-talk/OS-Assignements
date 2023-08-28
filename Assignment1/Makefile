q1.1: q1.1.c
	gcc q1.1.c -o q1.1

q1.2.1: q1.2.1.c
	gcc q1.2.1.c -o q1.2.1

q1.2.2: q1.2.2.c
	gcc q1.2.2.c -o q1.2.2

q2: q2.c
	gcc q2.c -o q2

run_p: q1.1 q1.2.1 q1.2.2 q2
	echo "The output for the first question first part.\n\n"
	./q1.1

	echo "The output for the first question second part.\n\n"
	./q1.2.1
	
	echo "The output for the first question second part(bonus).\n\n"
	./q1.2.2

	echo "The output for the second part.\n\n"
	./q2  # Corrected executable name

clean:
	rm -f q1.1 q1.2.1 q1.2.2 q2 

all: q1 q2 run_p clean
