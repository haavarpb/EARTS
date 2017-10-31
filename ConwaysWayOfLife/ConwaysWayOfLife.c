#include "ConwaysWayOfLife.h"

int cellArrayRows;
int cellArrayCols;
int **cellArray = NULL;

int rPentomino[5][5] = { {0, 0, 0, 0, 0},
						 {0, 0, 1, 1, 0},
						 {0, 1, 1, 0, 0},
						 {0, 0, 1, 0, 0},
						 {0, 0, 0, 0, 0}};

int dieHard[5][10] = {	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
						{0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
						{0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
						{0, 0, 1, 0, 0, 0, 1, 1, 1, 0},
						{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

int acorn[5][10] = {	{0, 0, 0, 0, 0, 0, 0, 0, 0},
						{0, 0, 1, 0, 0, 0, 0, 0, 0},
						{0, 0, 0, 0, 1, 0, 0, 0, 0},
						{0, 1, 1, 0, 0, 1, 1, 1, 0},
						{0, 0, 0, 0, 0, 0, 0, 0, 0}};

void evaluateCells(){
	for(int row = 0; row < cellArrayRows; row++){
		for(int col = 0; col < cellArrayCols; col++){
			int numNeighbours = countNeighbours(row, col);
			if (cellArray[row][col]){
				if (numNeighbours < 2){
					cellArray[row][col] = 0;
				}
				else if (numNeighbours >= 2 && numNeighbours <= 3){
					continue;							
				}
				else if (numNeighbours > 3){
					cellArray[row][col] = 0;
				}
			}
			else{
				if(numNeighbours == 3){
					cellArray[row][col] = 1;
				}
			}
			writeGridToScreen(cellArray, cellArrayRows, cellArrayCols);
		}
	}
}

int countNeighbours(int row, int col){
	int numNeighbours = 0;
	for(int offsetRow = -1; offsetRow <= 1; offsetRow++){
		for(int offsetCol = -1; offsetCol <= 1; offsetCol++){
			if (indexInRange(row + offsetRow, col + offsetCol)){
				if (cellArray[row + offsetRow][col + offsetCol]){
					numNeighbours++;
				}
			}
			else{
				continue;
			}
		}
	}
	return numNeighbours;
}

int indexInRange(int indexRow, int indexCol){
	if (indexRow < 0 || indexRow >= cellArrayRows){
		return 0;
	}
	else if (indexCol < 0 || indexCol >= cellArrayCols){
		return 0;
	}
	else{
		return 1;
	}
}

void mallocCellArray(){
	cellArray = (int **) malloc(cellArrayRows*sizeof(int *));
	for(int row = 0; row < cellArrayRows; row++){
		cellArray[row] = (int *) malloc(cellArrayCols*sizeof(int));
	}
}

void freeCellArray(){
	for(int row = 0; row < cellArrayRows; row++){
		free(cellArray[row]);
	}
	free(cellArray);
}
void instantiateCellArray(){
	//cellArrayRows = getScreenSize()->maxY;
	//cellArrayCols = getScreenSize()->maxX;
	cellArrayRows = 30;
	cellArrayCols = 50;
	mallocCellArray();
	for(int row = 0; row < cellArrayRows; row++){
		for(int col = 0; col < cellArrayCols; col++){
			cellArray[row][col] = 0;
		}
	}
}

int getCellRows(){return cellArrayRows;}
int getCellCols(){return cellArrayCols;}

void insertPreset(cellArrayPresets_t preset){
	if (preset == e_Random){
		srand(time(NULL));
		for(int offsetRow = 0; offsetRow < 5; offsetRow++){
			for (int offsetCol = 0; offsetCol < 10; offsetCol++){
				if (rand() % 100 > 50){
					cellArray[cellArrayRows/2 + offsetRow][cellArrayCols/2 + offsetCol] = 1;
				}
			}
		}
	}
	else{
		if (preset == e_rPentomino){
			int aSizeRow = sizeof(rPentomino) / sizeof(rPentomino[0]);
			int aSizeCol = sizeof(rPentomino[0])/sizeof(rPentomino[0][0]);
			for (int offsetR = 0; offsetR < aSizeRow; offsetR++){
				for (int offsetC = 0; offsetC < aSizeCol; offsetC++){
					cellArray[cellArrayRows/2 + offsetR][cellArrayCols/2 + offsetC] = rPentomino[offsetR][offsetC];
				}
			}
		}
		else if(preset == e_dieHard){
			int bSizeRow = sizeof(dieHard) / sizeof(dieHard[0]);
			int bSizeCol = sizeof(dieHard[0])/sizeof(dieHard[0][0]);
			for (int offsetR = 0; offsetR < bSizeRow; offsetR++){
				for (int offsetC = 0; offsetC < bSizeCol; offsetC++){
					cellArray[cellArrayRows/2 + offsetR][cellArrayCols/2 + offsetC] = dieHard[offsetR][offsetC];
				}
			}
		}
		else if(preset == e_acorn){
			int cSizeRow = sizeof(acorn) / sizeof(acorn[0]);
			int cSizeCol = sizeof(acorn[0])/sizeof(acorn[0][0]);
			for (int offsetR = 0; offsetR < cSizeRow; offsetR++){
				for (int offsetC = 0; offsetC < cSizeCol; offsetC++){
					cellArray[cellArrayRows/2 + offsetR][cellArrayCols/2 + offsetC] = acorn[offsetR][offsetC];
				}
			}
		}
	}
	writeGridToScreen(cellArray, cellArrayRows, cellArrayCols);
}

/* Public functions */

int getCellArrayRows(){return cellArrayRows;}
int getCellArrayCols(){return cellArrayCols;}
