output: main.o function.o
	gcc main.o function.o -o output

main.o: main.c heap.h
	gcc -c main.c

function.o: function.c heap.h
	gcc -c function.c

clean:
	rm *.o output