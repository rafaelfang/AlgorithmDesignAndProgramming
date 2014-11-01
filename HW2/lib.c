#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"

//Parameters:
//fName : The first name of a passenger
//lName : The last name of a passenger
//origin: A passengers origin
//dest  : A passengers destination
//
//Return: A seat struct populated with the specified information
//
//Each of the strings malloced inside of the struct should be the exact size
//of the string that it holds. So, if a passengers first name is Seth then 
//seat->fName should point to exactly 5 characters; one for each letter in
//the name plus the null terminater. 
//
Seat* create_seat(char* fName, char* lName, char* origin, char* dest, int num) {
	printf("%s %s got on the plane in %s\n",fName,lName,origin);
	Seat* seatNode=malloc(sizeof(Seat));
	seatNode->fName=malloc(sizeof(char)*(strlen(fName)+1));
	seatNode->lName=malloc(sizeof(char)*(strlen(lName)+1));
	seatNode->origin=malloc(sizeof(char)*(strlen(origin)+1));
	seatNode->destination=malloc(sizeof(char)*(strlen(dest)+1));
	
	strcpy(seatNode->fName,fName);
	strcpy(seatNode->lName,lName);
	strcpy(seatNode->origin,origin);
	strcpy(seatNode->destination,dest);
	seatNode->seatNumber=num;

	seatNode->next=NULL;
	return seatNode;

}

//Parameters:
//seat : A double pointer to a seat struct
//
//Return : Nothing
//
//This function should properly free all the memory inside of a seat and
//set the seat equal to NULL so it may not be referenced by other 
//functions
void  empty_seat(Seat** seat) {
	printf("%s %s left the plane in %s\n",(*seat)->fName,(*seat)->lName,(*seat)->destination);
	free((*seat)->fName);
	free((*seat)->lName);
	free((*seat)->origin);
	free((*seat)->destination);
	
	free(*seat);
	*seat=NULL;

}

//Parameters: 
//plane : the head of a linked list
//seat  : a pointer to a seat
//
//Return: The possibly updated head of the linked list
//
//This function should insert the seat into the plane list in sorted order
//by seat number recursively 
Seat* check_in(Seat* plane, Seat* seat) {
	if(plane==NULL){
		return seat;
	}else if(plane->seatNumber>seat->seatNumber){
		seat->next=plane;
		return seat;
	}else{
		plane->next=check_in(plane->next, seat);
		return plane;
	
	}
}


//Parameters:
//plane : the head of a linked list
//location: the current location of the plane
//
//Return : The possibly updated head of the plane list
//
//This method should recursively remove each seat from the plane
//that has the current location as its destination and pass it to 
//empty seat
Seat* land(Seat* plane, char* location) {
	if(plane==NULL){
		//printf("get called empty\n");
		return plane;
	}else if(strcmp(plane->destination,location)==0){
		//printf("%s get called %s\n",plane->destination,location);
		Seat* prev=plane;
		plane=plane->next;
		empty_seat(&prev);
		return land(plane,location);
	}else{
		//printf("%s get calledasdfasdf %s\n",plane->destination,location);
		plane->next=land(plane->next,location);
		return plane;
	}
}
