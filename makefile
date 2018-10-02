all: struct.c
	gcc struct.c -o struct

run: struct
	./struct

clean:
	rm struct
