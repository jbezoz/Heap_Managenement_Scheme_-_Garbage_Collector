output: main.o function.o GC.o
	gcc main.o function.o GC.o -o output

main.o: main.c heap.h gc.h
	gcc -c main.c

function.o: function.c heap.h
	gcc -c function.c

GC.o: GC.c gc.h
	gcc -c GC.c

clean:
	rm *.o output