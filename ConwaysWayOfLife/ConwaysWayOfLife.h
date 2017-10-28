#ifndef CONWAYSWAYOFLIFE_H_
#define CONWAYSWAYOFLIFE_H_
#include <stddef.h>
#include <stdlib.h>
#include <time.h>
#include "GUI.h"
#include "Cell_t.h"

static int cellArrayRows;
static int cellArrayCols;

typedef enum{
	Random,
	Preset1,
	Preset2 // etc...
} cellArrayPresets_t;

void evaluateCells(int **cellArray);
int countNeighbours(int **cellArray, int row, int col);
int indexInRange(int indexRow, int indexCol);
void mallocCellArray(int **cellArray);
void freeCellArray(int **cellArray);
void instantiateCellArray(int **cellArray, cellArrayPresets_t preset);
int getCellArrayRows();
int getCellArrayCols();


#endif /* CONWAYSWAYOFLIFE_H_ */
