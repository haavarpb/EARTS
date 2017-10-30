#include "GUI.h"
#include <curses.h>
#include <string.h>

struct scrSize *screenSize = NULL;

void initializeWindow(){
	initscr();
	setScreenSize(screenSize);
	noecho();
	refresh();
}

struct scrSize *getScreenSize(){
	return screenSize;
}
void setScreenSize(struct scrSize *screenSize){
	int x, y;
	getmaxyx(stdscr, y, x);
	screenSize->maxY = y;
	screenSize->maxX = x;
}

void writeGridToScreen(int **cellArray,int cellArrayRows,int cellArrayCols){
	for(int row = 0; row < cellArrayRows; row++){
		for(int col = 0; col < cellArrayCols; col++){ 
			if (cellArray[row][col] == 1){
				addch("0x25A0");
			}
			else {
				addch("0x25A1");
			}
			if(col == cellArrayRows-1){
				printw("\n");
			}
		}
	updateWindow();
}

void updateWindow(){
	sleep(0.5);
	erase();
}

void writeTextToScreen(struct scrSize *screenSize, char *text){
		int textLength = strlen(text);
		mvprintw((screenSize->maxY)/2, (screenSize->maxX)/2 - textLength/2 , text);	
		refresh();
}


void terminateWindow(){
	endwin();
}
