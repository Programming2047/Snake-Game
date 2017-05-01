#include <unistd.h>
#include <termios.h>
#include <stdio.h>
#include <stdlib.h>
	
struct termios rettonorm;

void entergamemode() {	// Sets the terminal in a non-return mode
	tcgetattr(STDIN_FILENO,&rettonorm);
//makes sure input and stuff isn't shown
	struct termios game = rettonorm;
	
	game.c_lflag &= ~(ECHO | ICANON);
	game.c_oflag &= ~(OPOST);
	game.c_iflag &= ~(ICRNL | IXON);
	game.c_cc[VMIN] = 0;
	game.c_cc[VTIME] = 20;// amout of time to give fro user to add input for read() inn tenths of sec
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &game);
}

void endgame() { //returns the terminal to regular
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &rettonorm);
}

int main() {
	entergamemode();
	
	char inp = '\0'; //initializing variable
	while (1) {		
		read(STDIN_FILENO, &inp, 1); //reads for 2 seconds
		printf("%d \r\n",inp); //prints the character pressed
    system("clear")
	}
	endgame();
}
