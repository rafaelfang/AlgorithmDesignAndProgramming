a.out: runner.o set.o
	gcc runner.o set.o -o a.out

runner.o: runner.c set.h
	gcc -c runner.c

set.o:	set.c set.h
	gcc -c set.c

clean:
	rm *.o a.out