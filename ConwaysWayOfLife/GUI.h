#ifndef GUI_H_
#define GUI_H_
#include <unistd.h>
#include <stdio.h>
#include <curses.h>
#include "Cell_t.h"

struct scrSize{
	int maxX;
	int maxY;
};

struct scrSize * getScreenSize();
void setScreenSize(struct scrSize *);
void initializeWindow();
void writeToScreen(cell_t **cellArray);
void terminateWindow();

#endif /* GUI_H_ */
