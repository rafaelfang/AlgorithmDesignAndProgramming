#include <stdlib.h>
#include <string.h>
#include "queue.h"


Queue* enqueue(Queue* queue, char* data){
	if(queue==NULL){
		Queue* newNode=malloc(sizeof(Queue));
		newNode->data=malloc(sizeof(char)*(strlen(data)+1));
		strcpy(newNode->data,data);
		newNode->next=NULL;
		return newNode;
	}else{
		queue->next=enqueue(queue->next,data);
		return queue;
	}

}
char* dequeue(Queue** queue){
	if(*queue==NULL){
		return NULL;
	}else{
		Queue* prev=*queue;
		char* str=prev->data;
		*queue=(*queue)->next;
		free(prev);
		return str;
	}
}
int size(Queue* queue){
	if(queue==NULL){
		return 0;
	}else{
		return 1+size(queue->next);
	}

}