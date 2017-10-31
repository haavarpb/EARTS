#ifndef CONWAYSWAYOFLIFE_H_
#define CONWAYSWAYOFLIFE_H_
#include <stddef.h>
#include <stdlib.h>
#include <time.h>
#include "GUI.h"

extern int cellArrayRows;
extern int cellArrayCols;
extern int **cellArray;

typedef enum{
	e_Random,
	e_rPentomino,
	e_dieHard,
	e_acorn
} cellArrayPresets_t;

extern int rPentomino[5][5];

extern int dieHard[5][10];

extern int acorn[5][10];

void evaluateCells();

int countNeighbours(int row, int col);
int indexInRange(int indexRow, int indexCol);
void mallocCellArray();
void freeCellArray();
void instantiateCellArray();
int getCellArrayRows();
int getCellArrayCols();
void insertPreset(cellArrayPresets_t preset);
void copyPresetToCellArray(int *pre[]);
int getCellRows();
int getCellCols();

#endif /* CONWAYSWAYOFLIFE_H_ */
