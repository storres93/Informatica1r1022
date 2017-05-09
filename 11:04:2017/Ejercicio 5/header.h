#include <stdio.h>
#define ROWS 3
#define COLUMNS 3
#define CROSS 'x'
#define CIRCLE 'o'
#define NOT_USED ' '
#define STRING_NULL '\0'

void printBoard(char[ROWS][COLUMNS]);
void initializeBoard(char[ROWS][COLUMNS]);
int checkIfWinned(char[ROWS][COLUMNS]);
void playTurn(char[ROWS][COLUMNS], char);
int validMove(char[ROWS][COLUMNS], int, int);


