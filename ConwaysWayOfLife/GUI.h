#ifndef GUI_H_
#define GUI_H_
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <curses.h>
#include "ConwaysWayOfLife.h"

typedef struct{
	int maxX;
	int maxY;
}scrSize;

extern scrSize screenSize;

scrSize getScreenSize();
void setScreenSize();
void initializeWindow();
void writeGridToScreen(int **array,int sizeRows,int sizeCols);
void writeTextToScreen(char *text);
void terminateWindow();

#endif /* GUI_H_ */
