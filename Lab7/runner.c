#include <stdio.h>
#include <stdlib.h>
#include "set.h"

Set* create_list(char* file){
	FILE *ptr_file=fopen(file,"r");
	int tempVal;
	Set* myList=NULL;
	while(fscanf(ptr_file, "%d", &tempVal)!=EOF){
		//printf("%d",tempVal);
		myList=set_insert (myList , tempVal );

	}
	return myList;
}

int main(int argc, char* argv[]){
	if(argc!=4){
		printf("Incorrect number of command line arguments\n");
		printf("Correct usage: ./a.out <input1.txt> <input2.txt> <a number>\n");
		return -1;	
	}
	Set* first=create_list(argv[1]);
	printf("First Set:\n");
	print_list(first);
	Set* second=create_list(argv[2]);
	printf("Second Set:\n");
	print_list(second);
	Set* intersection=set_intersection(first,second);
	printf("Intersection of the two sets:\n");
	print_list(intersection);
	
	
	intersection=set_remove(intersection, atoi(argv[3]));
	printf("intersection without %d\n",atoi(argv[3]));
	print_list(intersection);
	
	printf("The midpoint of the intersection is %d\n",getMiddle(intersection));
	
	
	return 0;
}

