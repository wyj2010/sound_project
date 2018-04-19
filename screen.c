//contains screen manipulation functions, such as clearScreen(), gotoxy(), setColor(), etc.
#include <stdio.h>
#include "comm.h"
#include "screen.h"

/*
	Function definition of clearScreen()
	This function will use VT100 escape sequence "\ESC[2J" to erase the whole total
	terminal screen.
	Input argument: none
	Return argument: none
*/
void clearScreen(void){
	printf("%c[2J", ESC);
	fflush(stdout);
}
/*
	Function definition of gotoxy()
	This function uses VT100 escape sequence "\ESC[row;colH" to set cursor
	to the specific location of the terminal screen.
	Input argument:
		int row: row number (1 is top)
		int col: col number (1 is left)
	Return argument: none
*/
void gotoxy(int row, int col){
	printf("%c[%d;%dH", ESC, row, col);
	fflush(stdout);
}
/*
	Function definition of setColor()
	This function uses VT100 escape sequence "\ESC[1;colorm" to set the
	color for the bar graph and the information of the .wav file.
	Input argument:
		int color: determine the color
	Return argument: none
*/
void setColor(int color){
	printf("%c[1;%dm", ESC, color);
	fflush(stdout);
}
/*
	Function definition of bar()
	This function uses the gotoxy() function and prints out the bar graph
	representing the dB values of the .wav file. It also has the setColor()
	function to set different color for the dB values.
	Input argument:
		int col: col number (1 is left)
		double dB: the sound value in decibels
	Return argument: none
*/
void bar(int col, double dB){
	int i;
	for(i=0; i < dB/4; i++){
		gotoxy(25-i, col+1);	//the first bar starts from col = 1
#ifndef UNICODE
		printf("%c", '*');
#else
		//white bar if dB below 60
		if(i < 60/4){
			setColor(WHITE);
		}else if(i < 80/4){		//yellow bar if dB between 60 and 80
			setColor(YELLOW);
		}else{
			setColor(RED);		//red bar if dB over 80
		}
		printf("%s", BAR);
#endif
	}
}
