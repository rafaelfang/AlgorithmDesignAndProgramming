#include <stdio.h>
#include <stdlib.h>
#include "minesweeper.h"


int main(int argc, char* argv[]){

	
	if(argc==1){
		printf("Incorrect number of command line arguments\n");
		printf("Correct usage: ./a.out <number of bombs>\n");
		return -1;	
	}
	PositionType board[BoardSize][BoardSize];
	int numberOfBomb=atoi(argv[1]);
	int totalNumberOfSafePlace=BoardSize*BoardSize-numberOfBomb;
	
	setBoard(board,numberOfBomb);
	displayBoard(board);
	printf("Game begins, there are total %d grids, and there are %d bombs there, %d total safe grids.\n", BoardSize*BoardSize, numberOfBomb, totalNumberOfSafePlace);
	int row;
	int col;
	printf("Enter a row and col:\n");
	scanf("%d %d",&row,&col);
	
	int result;

	while(1){
		
		result=processGuess( board, row , col );
		
		
		switch(result){
				case -1:
					printf("Invalid position.\n");
					
					break;
				case 0:
					printf("That position has already been picked.\n");
					
					break;				
				case 1:
					totalNumberOfSafePlace--;
					break;
				case 2:
					printf("Game over, you lose\n");
					displayBoard(board);
					return -1;
				
		}
		
		displayBoard(board);
		if(totalNumberOfSafePlace==0){
			break;
		}
		printf("Total Number Of Safe Place Left: %d\n",totalNumberOfSafePlace);
		printf("Enter a row and col:\n");
		scanf("%d %d",&row,&col);
		

	}

	
	printf("You win!\n");
	

	return 0;

}
