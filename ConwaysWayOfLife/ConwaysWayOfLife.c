#include "ConwaysWayOfLife.h"

int **cellArray = NULL; // This is the actual board. A cell is alive if 1, dead otherwise

void evaluateCells(int **cellArray){
	for(int row = 0; row < cellArrayRows; row++){
		for(int col = 0; col < cellArrayCols; col++){
			int numNeighbours = countNeighbours(cellArray, row, col);
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
			
		}
	}
}

int countNeighbours(int **cellArray, int row, int col){
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

void mallocCellArray(int **cellArray){
	cellArray = (int **) malloc(cellArrayRows*sizeof(int *));
	for(int row = 0; row < cellArrayRows; row++){
		cellArray[row] = (int *) malloc(cellArrayCols*sizeof(int));
	}
}
void freeCellArray(int **cellArray){
	for(int row = 0; row < cellArrayRows; row++){
		free(cellArray[row]);
	}
	free(cellArray);
}
void instantiateCellArray(int **cellArray, cellArrayPresets_t preset){
	cellArrayRows = getScreenSize()->maxY;
	cellArrayCols = getScreenSize()->maxX;
	for(int row = 0; row < cellArrayRows; row++){
		for(int col = 0; col < cellArrayCols; col++){
			cellArray[row][col] = 0;
		}
	}

	if (preset == Random){
		srand(time(NULL));
		for(int offsetRow = 0; offsetRow < 3; offsetRow++){
			for (int offsetCol = 0; offsetCol < 3; offsetCol++){
				if (rand() % 100 > 50){
					cellArray[cellArrayRows/2 + offsetRow][cellArrayCols/2 + offsetCol] = 1;
				}
			}
		}
	}

	// Add more presets
}

/* Public functions */

int getCellArrayRows(){return cellArrayRows;}
int getCellArrayCols(){return cellArrayCols;}
