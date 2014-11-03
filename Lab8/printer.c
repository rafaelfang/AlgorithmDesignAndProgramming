#include <stdio.h>
#include <unistd.h>
#include "queue.h"

Queue* print(Queue* queue){

	sleep(1);
	while(queue!=NULL){
		printf("%s",dequeue(&queue));
	}
	return queue;
}

int main(int argc, char* argv[]){
	if(argc!=2){
		printf("Incorrect number of command line arguments\n");
		printf("Correct usage: ./a.out <input.txt>\n");
		return -1;	
	}
	FILE *ptr_file=fopen(argv[1],"r");
	char tempStr[100];
	Queue* myQueue=NULL;
	while(fgets(tempStr,100,ptr_file)!=NULL){
		
		myQueue=enqueue(myQueue, tempStr);
		if (size(myQueue) == 3) {
            myQueue=print(myQueue);
        }

	}
	
	myQueue=print(myQueue);
	
	
	return 0;

}