#include <stdlib.h>

typedef struct node_ {
	int data;
	struct node_* next;
}node;

node* insert_at_head(node* , int );
void print_list(node* );
void free_list(node* );
node* reverse_list(node*);
node* delete_from_head(node* );
node* insert_at_tail(node* , int );
node* delete_from_tail(node* );
