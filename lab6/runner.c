#include <stdio.h>
#include "list.h"

node* create_list(char* file){
	FILE *ptr_file=fopen(file,"r");
	int tempVal;
	node* myList=NULL;
	while(fscanf(ptr_file, "%d", &tempVal)!=EOF){
		//printf("%d",tempVal);
		myList=insert_at_head(myList , tempVal );

	}
	return myList;
}

int main(int argc, char* argv[]){
	if(argc==1){
		printf("Incorrect number of command line arguments\n");
		printf("Correct usage: ./a.out <input file>\n");
		return -1;	
	}
	node* myList=create_list(argv[1]);
	print_list(myList);
	myList= delete_from_head(myList);
	print_list(myList);
	myList=insert_at_tail(myList,99);
	print_list(myList);
	myList=delete_from_tail(myList);
	print_list(myList);
	myList=reverse_list(myList);
	print_list(myList);
	free_list(myList);
	return 0;
}
