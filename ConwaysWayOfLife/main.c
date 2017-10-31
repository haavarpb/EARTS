#include "FiniteStateMachine.h"

#include "GUI.h"
#include "ConwaysWayOfLife.h"

int inRange(int array[3][3], int sizeRow, int sizeCol, int indexRow, int indexCol){
	if (indexRow < 0 || indexRow >= 3){
		return 0;
	}
	else if (indexCol < 0 || indexCol >= 3){
		return 0;
	}
	else{
		return 1;
	}
}

int countN(int array[3][3], int row, int col){
	int numNeighbours = 0;
	for(int offsetRow = -1; offsetRow <= 1; offsetRow++){
		for(int offsetCol = -1; offsetCol <= 1; offsetCol++){
			if (inRange(array, row, col, row + offsetRow, col + offsetCol)){
				if (offsetCol == 0 && offsetRow == 0){
					continue;
				}
				if (array[row + offsetRow][col + offsetCol]){
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

int main(){
	initializeWindow();
	int row = 3;
	int col = 3;
	int arr[3][3] = {{1, 1, 1},{1, 1, 1},{1, 1, 1}};
	int neighbours[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++){
			mvprintw(i, j, "%d", arr[i][j]);
			if (arr[i][j]){
				neighbours[i][j] = countN(arr, i, j);
			}
			mvprintw(i + 4, j, "%d", neighbours[i][j]);
		}
	}
	refresh();
	sleep(100);
	return 0;
}
