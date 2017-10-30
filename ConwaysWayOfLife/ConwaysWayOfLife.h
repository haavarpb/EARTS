#ifndef CONWAYSWAYOFLIFE_H_
#define CONWAYSWAYOFLIFE_H_
#include <stddef.h>
#include <stdlib.h>
#include <time.h>
#include "GUI.h"
#include "Cell_t.h"

static int cellArrayRows;
static int cellArrayCols;
static int **cellArray = NULL; // This is the actual board. A cell is alive if 1, dead otherwise

typedef enum{
	e_Random,
	e_rPentomino,
	e_dieHard,
	e_acorn
} cellArrayPresets_t;

static int rPentomino[5][5] = { {0, 0, 0, 0, 0},
								{0, 0, 1, 1, 0},
								{0, 1, 1, 0, 0},
								{0, 0, 1, 0, 0},
								{0, 0, 0, 0, 0}};

static int dieHard[5][10] = {	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
								{0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
								{0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
								{0, 0, 1, 0, 0, 0, 1, 1, 1, 0},
								{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

static int acorn[5][10] = {	{0, 0, 0, 0, 0, 0, 0, 0, 0},
							{0, 0, 1, 0, 0, 0, 0, 0, 0},
							{0, 0, 0, 0, 1, 0, 0, 0, 0},
							{0, 1, 1, 0, 0, 1, 1, 1, 0},
							{0, 0, 0, 0, 0, 0, 0, 0, 0}};

void evaluateCells();

int countNeighbours(int row, int col);
int indexInRange(int indexRow, int indexCol);
void mallocCellArray();
void freeCellArray();
void instantiateCellArray();
int getCellArrayRows();
int getCellArrayCols();
void insertPreset(cellArrayPresets_t preset);
void copyPresetToCellArray(cellArrayPresets_t preset);

#endif /* CONWAYSWAYOFLIFE_H_ */
