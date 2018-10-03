all: struct.o
	gcc struct.o -o struct

run: all
	./struct

struct.o: struct.c
	gcc -c struct.c

clean:
	rm *.o
	rm struct
