
//board for the game
#include <stdio.h>


#define BOARD_X  80
#define BOARD_Y  40



// Initializing the board
int  board()
{

	
	int x;
	int y;

	char  board[BOARD_Y][BOARD_X];
	//looping through the board
	for(int y = 0; y < BOARD_Y; y++) {
		for(int x = 0; x < BOARD_X; x++) {
			//even row
			if((x + y) % 2 == 0)
				board[y][x] = '|';
			else
				board[y][x] = '|';
		}
	}

	//display the board
	for(int y = 0; y < BOARD_Y; y++) {
		for(int x = 0; x < BOARD_Y; x++) {
			printf("%s",&board[y][x]);
			printf("   ");
		}
		printf("\n");
	}

	return 0;
}

int main()
{


	board();


	return 0;
}

