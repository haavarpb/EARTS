#include "GUI.h"

// CODER 2

scrSize screenSize;

void initializeWindow(){
	initscr();
	setScreenSize();
	noecho();
}

scrSize getScreenSize(){
	return screenSize;
}

void setScreenSize(){
	getmaxyx(stdscr, screenSize.maxY, screenSize.maxX);
}

void writeGridToScreen(int **array,int sizeRows,int sizeCols){
	for(int row = 0; row < sizeRows; row++){
		for(int col = 0; col < sizeCols; col++){
			if (array[row][col] == 1){
				mvaddch(row, col, '#');
			}
			else {
				mvaddch(row, col, ' ');
			}
		}
	}
	refresh();
}

void writeTextToScreen(char* text){
	mvprintw(0, 0 , text);
	refresh();
	sleep(1);
}


void terminateWindow(){
	endwin();
}
