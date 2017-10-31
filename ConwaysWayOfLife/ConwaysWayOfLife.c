#include "ConwaysWayOfLife.h"

// CODER 3

int cellArrayRows;
int cellArrayCols;
int **cellArray = NULL;
int **copyArray = NULL;

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
			int numNeighbours = countNeighbours(cellArray, row, col, cellArrayRows, cellArrayCols);
			if (cellArray[row][col]){
				if (numNeighbours < 2){
					copyArray[row][col] = 0;
				}
				else if (numNeighbours >= 2 && numNeighbours <= 3){
					continue;							
				}
				else if (numNeighbours > 3){
					copyArray[row][col] = 0;
				}
			}
			else{
				if(numNeighbours == 3){
					copyArray[row][col] = 1;
				}
			 cellArray[row][col] = 0;
			}
		}
	}

	//Swap the pointers of the two tables
	int **temp = cellArray;
	cellArray = copyArray;
	copyArray = temp;

	writeGridToScreen(cellArray, cellArrayRows, cellArrayCols);
}

int countNeighbours(int **mat,int i, int j, int n,int m)
{
    int counter=0,row_index=0,column_index=0;
    for(row_index=i-1;row_index<=i+1;row_index++)
    {
        for(column_index=j-1;column_index<=j+1;column_index++)
        {
            if((row_index>=0)&&(row_index<n)&&(column_index>=0)&&(column_index<m))
            {
                if((mat[row_index][column_index]==1)||(mat[row_index][column_index]==2))
                    counter++;
                if((row_index==i)&&(column_index==j)&&(mat[i][j]==1))
                    counter--;
            }
        }
    }
    return counter;
}

int indexInRange(int indexRow, int indexCol){
	if (indexRow < 0 || indexRow >= MASKSIZE) {
		return 0;
	}
	else if (indexCol < 0 || indexCol >= MASKSIZE){
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

	copyArray = (int **) malloc(cellArrayRows*sizeof(int *));
		for(int row = 0; row < cellArrayRows; row++){
			copyArray[row] = (int *) malloc(cellArrayCols*sizeof(int));
		}
}

void freeCellArray(){
	for(int row = 0; row < cellArrayRows; row++){
		free(cellArray[row]);
	}
	free(cellArray);
	for(int row = 0; row < cellArrayRows; row++){
		free(copyArray[row]);
	}
	free(copyArray);
}
void instantiateCellArray(cellArrayPresets_t preset){
	cellArrayRows = getScreenSize().maxY;
	cellArrayCols = getScreenSize().maxX;
	mallocCellArray();
	for(int row = 0; row < cellArrayRows; row++){
		for(int col = 0; col < cellArrayCols; col++){
			cellArray[row][col] = 0;
			copyArray[row][col] = 0;
		}
	}
}

void insertPreset(cellArrayPresets_t preset){
	if (preset == e_Random){
		srand(time(NULL));
		for(int offsetRow = 0; offsetRow < cellArrayRows; offsetRow++){
			for (int offsetCol = 0; offsetCol < cellArrayCols; offsetCol++){
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
	writeGridToScreen(cellArray,  cellArrayRows, cellArrayCols);
}

/* Public functions */

int getCellArrayRows(){return cellArrayRows;}
int getCellArrayCols(){return cellArrayCols;}
