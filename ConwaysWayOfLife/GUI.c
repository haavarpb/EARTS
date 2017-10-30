#include "GUI.h"

scrSize *screenSize = NULL;

void initializeWindow(){
	initscr();
	printf("initscr\n");
	setScreenSize();
	printf("screen size set\n");
	noecho();
	updateWindow();
	printf("init done\n");
}

scrSize *getScreenSize(){
	return screenSize;
}

void setScreenSize(){
	int x, y;
	getmaxyx(stdscr, y, x);
	screenSize->maxY = y;
	screenSize->maxX = x;
}

void writeGridToScreen(int **cellArray,int cellArrayRows,int cellArrayCols){
	for(int row = 0; row < cellArrayRows; row++){
		for(int col = 0; col < cellArrayCols; col++){ 
			if (cellArray[row][col] == 1){
				addch('#');
			}
			else {
				addch(' ');
			}
			if(col == cellArrayRows-1){
				printw("\n");
			}
		}
	}
	updateWindow();
}

void updateWindow(){
	sleep(0.5);
	erase();
}

void writeTextToScreen(char* text){
		int textLength = strlen(text);
		mvprintw((screenSize->maxY)/2, (screenSize->maxX)/2 - textLength/2 , text);	
		updateWindow();
}


void terminateWindow(){
	endwin();
}
