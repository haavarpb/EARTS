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

void writeToScreen(int **cellArray){
	addchar(ACS_BLOCK);
}

void terminateWindow(){
	endwin();
}
