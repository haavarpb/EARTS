#include "GUI.h"

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

void writeGridToScreen(int **cellArray, cellArrayRows, cellArrayCols){
	for(int row = 0; row < cellArrayRows; row++){
		for(int col = 0; col < cellArrayCols; col++){ 
			if (cellArray[row][col] == "1"){
				addchar("0x25A0");
			}
			else {
				addchar("0x25A1");
			}
	refresh();
}

void writeTextToScreen(struct scrSize *screenSize, char *text){
		textLength = strlen(text);
		mvprintw((screenSize->maxY)/2, (screenSize->maxX)/2 - textLength/2 , text);	
		refresh();

}

q

void terminateWindow(){
	endwin();
}
