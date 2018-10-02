all: struct.o
	gcc struct.o -o struct

run: all
	clear
	./struct

struct.o: struct.c struct.h
	gcc -c struct.c

clean:
	rm *.o
	rm struct
