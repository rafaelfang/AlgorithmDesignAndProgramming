printer: printer.c queue.o
	gcc printer.c queue.o -o printer

queue.o: queue.c queue.h
	gcc queue.c -c

clean: 
	rm *.o printer
