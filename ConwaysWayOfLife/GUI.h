#ifndef GUI_H_
#define GUI_H_
#include <unistd.h>
#include <stdio.h>
#include <ncurses.h>



struct scrSize{
	int maxX;
	int maxY;
};

struct scrSize * getScreenSize();
void setScreenSize(struct scrSize *);
void initializeWindow();
void updatingWindow();
void writeGridToScreen(int **cellArray,int cellArrayRows,int cellArrayCols);
void writeTextToScreen(struct scrSize *screenSize, char *text);
void terminateWindow();

#endif /* GUI_H_ */
