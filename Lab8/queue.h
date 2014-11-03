#ifndef QUEUE_H_
#define QUEUE_H_
typedef struct node_ {
    char* data;
    struct node_ *next;
} Queue;

Queue* enqueue(Queue* queue, char* data); 
char* dequeue(Queue** queue);
int size(Queue* queue);

#endif
