#include "header.h"

int main(void)
{
	char board[ROWS][COLUMNS];
	int wonBy = 0;
	char player = CROSS;

	initializeBoard(board);

	printBoard(board);

	while(!wonBy)
	{
		playTurn(board, player);
		printBoard(board);
		player = (player == CROSS) ? CIRCLE : CROSS;
		wonBy = checkIfWinned(board);
	}

	if(wonBy == -1)
		printf("It's a tie!");
	else
		printf("The player %c won!", (wonBy == 1) ? CROSS : CIRCLE);

	return 0;
}

void playTurn(char board[ROWS][COLUMNS], char player)
{
	int row, column;
	printf("Player %c choose your position by typing: ROWxCOLUMN\n", player);
	scanf("%dx%d", &row, &column);

	if(!validMove(board,row,column))
	{
		printf("That is not a valid move, please enter again\n");
		playTurn(board, player);
		return;
	}

	board[row][column] = player;
}

int validMove(char board[ROWS][COLUMNS], int row, int column)
{
	if(board[row][column] != NOT_USED)
		return 0;
	else
		return 1;
}

int checkIfWinned(char board[ROWS][COLUMNS])
{
	int checkedP1 = 0;
	int checkedP2 = 0;
	int i, j;

	//First we check if they made any row
	for(i = 0; i < ROWS; i++)
	{
		for(j=0; j<COLUMNS; j++) {
			if(board[i][j] == CROSS)
				checkedP1++;
			else if(board[i][j] == CIRCLE)
				checkedP2++;
			else
				break;
		}

		if(checkedP1 == 3)
			return 1;
		if(checkedP2 == 3)
			return 2;

		checkedP1 = checkedP2 = 0;
	}

	//Now we check for column win
	for(i = 0; i < ROWS; i++)
	{
		for(j=0; j<COLUMNS; j++) {
			if(board[j][i] == CROSS)
				checkedP1++;
			else if(board[j][i] == CIRCLE)
				checkedP2++;
			else
				break;
		}

		if(checkedP1 == 3)
			return 1;
		if(checkedP2 == 3)
			return 2;

		checkedP1 = checkedP2 = 0;
	}

	//now we check for diagonals
	for(i =0; i < ROWS; i++)
	{
		if(board[i][i] == CROSS)
			checkedP1++;
		else if(board[i][i] == CIRCLE)
			checkedP2++;
		else
			break;
	}

	if(checkedP1 == 3)
		return 1;
	if(checkedP2 == 3)
		return 2;

	return 0;
}

void initializeBoard(char board[ROWS][COLUMNS])
{
	int i, j;
	for(i=0; i<ROWS; i++) {
		for(j=0; j<COLUMNS; j++) {
			board[i][j] = NOT_USED;
		}
	}
}

void printBoard(char board[ROWS][COLUMNS])
{
	int i, j;
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			if(j == 1)
				printf("|");
			printf(" %c ", board[i][j]);
			if(j == 1)
				printf("|");
		}
		if(i != 2) printf("\n-----------");
		printf("\n");
	}
}