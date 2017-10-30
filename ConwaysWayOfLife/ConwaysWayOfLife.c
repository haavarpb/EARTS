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
	cellArrayRows = getScreenSize()->maxY;
	cellArrayCols = getScreenSize()->maxX;
	mallocCellArray();
	for(int row = 0; row < cellArrayRows; row++){
		for(int col = 0; col < cellArrayCols; col++){
			cellArray[row][col] = 0;
		}
	}
}


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
		copyPresetToCellArray(preset);
	}
}

void copyPresetToCellArray(cellArrayPresets_t preset){
	int **temp;
	if (preset == e_rPentomino){
		temp = rPentomino;
	}
	else if(preset == e_dieHard){
		temp = dieHard;
	}
	else if(preset == e_acorn){
		temp = acorn;
	}
	int tempSizeRow = sizeof(temp) / sizeof(temp[0]);
	int tempSizeCol = sizeof(temp[0])/tempSizeRow;

	for (int offsetR = 0; offsetR < tempSizeRow; offsetR++){
		for (int offsetC = 0; offsetC < tempSizeCol; offsetC++){
			cellArray[cellArrayRows/2 + offsetR][cellArrayCols/2 + offsetC] = temp[offsetR][offsetC];
		}
	}
}

/* Public functions */

int getCellArrayRows(){return cellArrayRows;}
int getCellArrayCols(){return cellArrayCols;}
