#include "ConwaysWayOfLife.h"

cell_t **cellArray = NULL;

void evaluateCells(cell_t **cellArray){
	for(int row = 0; row < cellArrayRows; row++){
		for(int col = 0; col < cellArrayCols; col++){
			int numNeighbours = countNeighbours(cellArray, row, col);
			if (cellArray[row][col].isAlive){
				if (numNeighbours < 2){
					cellArray[row][col].isAlive = 0;
				}
				else if (numNeighbours >= 2 && numNeighbours <= 3){
					continue;							
				}
				else if (numNeighbours > 3){
					cellArray[row][col].isAlive = 0;
				}
			}
			else{
				if(numNeighbours == 3){
					cellArray[row][col].isAlive = 1;
				}
			}
			
		}
	}
}

int countNeighbours(cell_t **cellArray, int row, int col){
	int numNeighbours = 0;
	for(int offsetRow = -1; offsetRow <= 1; offsetRow++){
		for(int offsetCol = -1; offsetCol <= 1; offsetCol++){
			if (indexInRange(row + offsetRow, col + offsetCol)){
				if (cellArray[row + offsetRow][col + offsetCol].isAlive){
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

void mallocCellArray(cell_t **cellArray){
	cellArray = (cell_t **) malloc(cellArrayRows*sizeof(cell_t *));
	for(int row = 0; row < cellArrayRows; row++){
		cellArray[row] = (cell_t *) malloc(cellArrayCols*sizeof(cell_t));
	}
}
void freeCellArray(cell_t **cellArray){
	for(int row = 0; row < cellArrayRows; row++){
		free(cellArray[row]);
	}
	free(cellArray);
}
void instantiateCellArray(cell_t **cellArray, cellArrayPresets_t preset){
	cellArrayRows = getScreenSize()->maxY;
	cellArrayCols = getScreenSize()->maxX;
	for(int row = 0; row < cellArrayRows; row++){
		for(int col = 0; col < cellArrayCols; col++){
			cellArray[row][col].isAlive = 0;
			cellArray[row][col].posX = col;
			cellArray[row][col].posY = row;
		}
	}

	if (preset == Random){
		srand(time(NULL));
		for(int offsetRow = 0; offsetRow < 3; offsetRow++){
			for (int offsetCol = 0; offsetCol < 3; offsetCol++){
				if (rand() % 100 > 50){
					cellArray[cellArrayRows/2 + offsetRow][cellArrayCols/2 + offsetCol].isAlive = 1;
				}
			}
		}
	}

	// Add more presets
}
