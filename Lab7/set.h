typedef struct node_ {
	int data;
	struct node_* next;
}Set;



Set* set_insert(Set* set, int data);
Set* set_remove(Set* set, int data);
Set* set_intersection(Set* first, Set* second);
void print_list(Set* list);
void free_list(Set* list);
int getMiddle(Set* list);