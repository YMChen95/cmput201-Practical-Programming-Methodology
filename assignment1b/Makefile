draw1b: draw1b.o
	gcc -Wall -std=c99 -o draw1b draw1b.o -lm

draw1b.o: draw1b.c draw1b.h
	gcc -Wall -std=c99 -c draw1b.c -g

clean:
	-rm -f *.o draw1b core
