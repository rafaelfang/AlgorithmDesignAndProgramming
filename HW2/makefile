a.out: main.o lib.o
	gcc main.o lib.o -o a.out

main.o: main.c lib.h
	gcc -c main.c

lib.o:	lib.c lib.h
	gcc -c lib.c

clean:
	rm *.o a.out