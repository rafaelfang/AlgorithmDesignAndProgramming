#include "set.h"
#include <stdlib.h>
#include <stdio.h>
int getMiddle(Set* list){
	Set* fast=list;
	Set* slow=list;
	while(fast!=NULL&&fast->next!=NULL){
		fast=fast->next->next;
		slow=slow->next;
	}
	
	return slow->data;

}


Set* set_insert(Set* set, int data){
	Set* begin=set;
	Set* head=malloc(sizeof(Set));
	head->data=data;
	
	while(set!=NULL){
		if(set->data==data){
			return begin;
		}else{
			set=set->next;
		}
	
	}
	
	head->next=begin;
	return head;

}

Set* set_remove(Set* set, int data){

	if(set==NULL){
		return NULL;
	}else if(set->data==data){
		Set* next=set->next;
		free(set);
		return set_remove(next,data);
		
	}else{
		set->next=set_remove(set->next,data);
		return set;
		
	}

}

Set* set_intersection(Set* first, Set* second){

	Set* intersection=NULL;
	while(first!=NULL){
		Set* cur=second;
		while(cur!=NULL){
			if(first->data==cur->data){
				Set* head=malloc(sizeof(Set));
				head->data=first->data;
				head->next=intersection;
				intersection=head;
				
			}
			
			cur=cur->next;
		}
		first=first->next;
	
	}
	return intersection;

}

void print_list(Set* list){

	while(list!=NULL){
		printf("%d->",list->data);
		list=list->next;
	}
	printf("NULL\n");


}

void free_list(Set* list){
	while(list!=NULL){
		Set* prev=list;
		list=list->next;
		free(prev);
	
	}


}