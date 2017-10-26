#ifndef GUI_H_
#define GUI_H_
#include <unistd.h>
#include <stdio.h>
#include <curses.h>

struct scrSize{
	int maxX;
	int maxY;
};

struct scrSize * getScreenSize();
void setScreenSize(struct scrSize *);
void initializeWindow();
void writeToScreen(int **cellArray);
void terminateWindow();

#endif /* GUI_H_ */
