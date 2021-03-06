typedef enum {
    covered,
    uncovered,
    coveredBomb,
    uncoveredBomb
} PositionType;

#define BoardSize 10

void setBoard(PositionType[BoardSize][BoardSize], int);
void displayBoard(PositionType board[BoardSize][BoardSize]);
int processGuess(PositionType board[BoardSize][BoardSize], int , int );
int findAdjacentBombs(PositionType board[BoardSize][BoardSize], int , int );
int isBomb(PositionType board[BoardSize][BoardSize], int , int );
