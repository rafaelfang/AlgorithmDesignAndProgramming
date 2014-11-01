#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lib.h"

int main(int argc, char* argv[]) {
   //TODO:
   //check for correct arguments
   if (argc < 2) {
        printf("Incorrect number of command line arguments\n");
        printf("Correct usage: %s <input 1> <input 2> . . . <input n>\n", argv[0]);
        return -1;
    }
	//read in the files
	int i=1;
	Seat* plane=NULL;
	for(i=1;i<argc;i++){
		FILE *ptr=fopen(argv[i],"r");
		if(ptr==NULL){
			continue;
		}
		plane=land(plane, strtok(argv[i],"."));
		char fName[20],lName[20],destination[20];
		int number;
		while(fscanf(ptr, "%s %s %s %d", fName, lName,destination,&number)!=EOF){
			
			plane=check_in(plane, create_seat(fName, lName, argv[i], destination, number));
		}
	}
	
   
   //logically assemble the code to match the output on the homework document
}
