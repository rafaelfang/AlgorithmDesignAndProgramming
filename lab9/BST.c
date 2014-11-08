#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "BST.h"

BST* insert(BST* tree,int data){

	if(tree==NULL){
		BST* newNode=malloc(sizeof(BST));
		newNode->data=data;
		newNode->left=NULL;
		newNode->right=NULL;
		return newNode;
	}else if(tree->data>data){
		tree->left=insert(tree->left,data);
		return tree;
	}else{
		tree->right=insert(tree->right,data);
		return tree;
	}

}

BST* find(BST* tree,int data){

	if(tree==NULL||tree->data==data){
		return tree;
	}else if(tree->data>data){
		
		return find(tree->left,data);
	}else{
		return find(tree->right,data);
	}

}

void inorder(BST* tree){
	if(tree!=NULL){
		inorder(tree->left);
		printf("%d ",tree->data);
		inorder(tree->right);
	}

}

void destroyTree(BST* tree){

	if(tree!=NULL){
		destroyTree(tree->left);
		destroyTree(tree->right);
		free(tree);
		
	}
}


BST* nearest(BST* tree, int data){
	int minDist=INT_MAX;
	BST* minDistNode=tree;
	int diff=0;
	while(tree!=NULL){
		diff=abs(tree->data-data);
		if(diff<minDist){
			minDistNode=tree;
			minDist=diff;
		}
		if(diff==0){
			break;
		}
		if(tree->data>data){
			tree=tree->left;
		}else{
			tree=tree->right;
		}

	}

	return minDistNode;

}
