#include "GUI.h"

scrSize *screenSize = NULL;

void initializeWindow(){
	initscr();
	//setScreenSize();
	noecho();
	clearWindow();
}

scrSize *getScreenSize(){
	return screenSize;
}

void setScreenSize(){
	getmaxyx(stdscr, screenSize->maxY, screenSize->maxX);
}

void writeGridToScreen(int **cellArray,int cellArrayRows,int cellArrayCols){
	for(int row = 0; row < cellArrayRows; row++){
		for(int col = 0; col < cellArrayCols; col++){ 
			if (cellArray[row][col] == 1){
				mvaddch(row, col, '#');
			}
			else {
				mvaddch(row, col, ' ');
			}
		}
	}
}

void clearWindow(){
	erase();
}

void writeTextToScreen(char* text){
	int textLength = strlen(text);
	mvprintw((getCellCols())/2, (getCellRows())/2 - textLength/2 , text);
	refresh();
}


void terminateWindow(){
	endwin();
}
