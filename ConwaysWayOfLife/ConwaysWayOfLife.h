#ifndef CONWAYSWAYOFLIFE_H_
#define CONWAYSWAYOFLIFE_H_
#include <stddef.h>
#include <stdlib.h>
#include <time.h>
#include "GUI.h"
#include "Cell_t.h"

int cellArrayRows;
int cellArrayCols;

typedef enum{
	Random,
} cellArrayPresets_t;

void evaluateCell(cell_t **cellArray);
int countNeighbours(cell_t **cellArray, int row, int col);
int indexInRange(int indexRow, int indexCol);

void mallocCellArray(cell_t **cellArray);
void freeCellArray(cell_t **cellArray);
void instantiateCellArray(cell_t **cellArray, cellArrayPresets_t preset);

#endif /* CONWAYSWAYOFLIFE_H_ */
