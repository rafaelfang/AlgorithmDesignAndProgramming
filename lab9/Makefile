BST: runner.o BST.o
	gcc runner.o BST.o -o BST

BST.o:	BST.c BST.h
	gcc -c BST.c

runner.o: runner.c BST.h
	gcc -c runner.c

clean:
	rm *.o BST
