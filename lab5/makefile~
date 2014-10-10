

a.out:runner.o minesweeper.o
	gcc runner.o minesweeper.o -o a.out

runner.o: runner.c minesweeper.h
	gcc -c runner.c

minesweeper.o: minesweeper.c minesweeper.h
	gcc -c minesweeper.c

clean:
	rm *.o a.out
