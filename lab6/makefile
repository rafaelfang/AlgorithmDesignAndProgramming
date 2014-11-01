a.out: runner.o list.o
	gcc runner.o list.o -o a.out

runner.o: runner.c list.h
	gcc -c runner.c

list.o:	list.c list.h
	gcc -c list.c

clean:
	rm *.o a.out
