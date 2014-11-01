#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "minesweeper.h"


void setBoard(PositionType board[BoardSize][BoardSize], int numMines){
	srand (time(NULL));
	int i;
	int j;
	for(i=0;i<BoardSize;i++){
		for(j=0;j<BoardSize;j++){
			board[i][j]=covered;
		}		

	}

	int mineLeft=numMines;
	int x;
	int y;
	while(mineLeft>0){
		x=rand()%10;
		y=rand()%10;
		if(board[x][y]==coveredBomb){
			continue;
		}else{
			board[x][y]=coveredBomb;
			mineLeft--;
		}
		
	}

}


void displayBoard(PositionType board[BoardSize][BoardSize]){
	int i;
	int j;
	int bombNearby;
	printf("     ");
	for(i=0;i<BoardSize;i++){
		printf("%d  ",i+1);
	}
	printf("\n");
	for(i=0;i<BoardSize;i++){
		printf("%2d  ",i+1);
		for(j=0;j<BoardSize;j++){
			switch(board[i][j]){
				case covered:
					//printf(" # ");
					//break;	
				case coveredBomb:
					//printf(" B ");
					printf(" # ");
					break;				
				case uncovered:
					bombNearby=findAdjacentBombs(board,i+1,j+1);
					//printf("newarby:%d",bombNearby);
					if(bombNearby==0){
						printf("   ");
					}else{
						printf(" %d ",bombNearby);
					}
					break;
				case uncoveredBomb:
					printf(" @ ");
					break;

			}
		}
		printf("\n");
	}

}



int findAdjacentBombs(PositionType board[BoardSize][BoardSize], int row, int col){
	int bombNearby=0;
	if(row==1&&col==1){
		return isBomb(board,1,2)+isBomb(board,2,2)+isBomb(board,2,1);
	}else if(row==1&&col==BoardSize){
		return isBomb(board,1,BoardSize-1)+isBomb(board,2,BoardSize-1)+isBomb(board,2,BoardSize);
	}else if(row==BoardSize&&col==1){
		return isBomb(board,BoardSize-1,1)+isBomb(board,BoardSize-1,2)+isBomb(board,BoardSize,2);
	}else if(row==BoardSize&&col==BoardSize){
		return isBomb(board,BoardSize-1,BoardSize-1)+isBomb(board,BoardSize-1,BoardSize)+isBomb(board,BoardSize,BoardSize-1);
	}else if(row==1){
		return isBomb(board,1,col-1)+isBomb(board,1,col+1)+isBomb(board,2,col-1)+isBomb(board,2,col)+isBomb(board,2,col+1);
	}else if(row==BoardSize){
		return isBomb(board,BoardSize,col-1)+isBomb(board,BoardSize,col+1)+isBomb(board,BoardSize-1,col-1)+isBomb(board,BoardSize-1,col)+isBomb(board,BoardSize-1,col+1);
	}else if(col==1){
		return isBomb(board,row-1,1)+isBomb(board,row+1,1)+isBomb(board,row-1,2)+isBomb(board,row,2)+isBomb(board,row+1,2);
	}else if(col==BoardSize){
		return isBomb(board,row-1,BoardSize)+isBomb(board,row+1,BoardSize)+isBomb(board,row-1,BoardSize-1)+isBomb(board,row,BoardSize-1)+isBomb(board,row+1,BoardSize-1);
	}else{
		return isBomb(board,row-1,col-1)+isBomb(board,row,col-1)+isBomb(board,row+1,col-1)+isBomb(board,row-1,col)+isBomb(board,row+1,col)+isBomb(board,row-1,col+1)+isBomb(board,row,col+1)+isBomb(board,row+1,col+1);
	}
	

}

int isBomb(PositionType board[BoardSize][BoardSize], int row, int col){
	int rowInd=row-1;
	int colInd=col-1;
	if(board[rowInd][colInd]==coveredBomb){
		return 1;
	}else{
		return 0;
	}
}



int processGuess(PositionType board[BoardSize][BoardSize], int row, int col ){
	if(row<1||row>BoardSize||col<1||col>BoardSize){
		return -1;
	}
	int rowInd=row-1;
	int colInd=col-1;
	switch(board[rowInd][colInd]){
			case covered:
				board[rowInd][colInd]=uncovered;
				return 1;	
			case coveredBomb:
				board[rowInd][colInd]=uncoveredBomb;
				return 2;
			case uncovered:
				return 0;
	}
	

}























