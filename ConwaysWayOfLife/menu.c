#include <stdio.h>
#include <stdlib.h>

int main(int choix)
{
    int choice=0;
    int presets=1;
    int start = 2;
    int row;
    int col;


        printf("\n\t     -Welcome to Game Of Life-\n");
        printf("\nRules Of The Game.\n");
        printf("1. A cells  is born in an empty  box when it has exactly 3 neighbors.\n");
        printf("2. A cells dies from loneliness if it has fewer than 2 neighbors.\n");
        printf("3. A cells dies  of overcrowding if it has more than 3 neighbors.\n");
        printf("4. Otherwise, the cells  survives.\n");
        printf("\nPlease select the option from Main Menu.\n");
        printf("\n\t\t:Main Menu:\n");
        choix = scanf("%d \n", &choice);

     if (choice == e_Random) {
     	     printf("\nThe Game is starting\n");
     	     printf("Choice your presets \n");
     	     printf("1. R-Pentomino");
     	     printf("2. dieHard");
     	     printf("3. Acom");
             scanf("%d \n", &presets);
        if (presets == 1)
        {
            presets = rPentomino;
                    else if  (presets == 2)
				    presets = dieHard;
				        else
				        presets = Acom;

		printf("Start the game ? 1/0");
                scanf(" %d", &start);
                if (start == 1);
                state = setstate (state_t s)(state= 1);
                 else
                 state = setstate (state_t s)(state= 0);

                 printf("exit the window");
        }

     }
     else
     {
      		 printf("\n2.Quit Game\n");
     }

}


void parseInput(){
	int input = readInput();
	switch((char) input){
	case 'q': // quit the entire game from anywhere
		state = QUIT;
		break;
	case 's':
		if MENU -> GAME
			insertPreset();
			state = GAME;
	default :
	}
}


void printLogo(){
	printf("\t\t##################\n");
	printf("\t\t@= GAME OF LIFE =@\n");
	printf("\t\t##################\n");
}

void printMenu(){
	printf("\n\t     -Welcome to Game Of Life-\n");
	        printf("\nRules Of The Game.\n");
	        printf("1. A cells  is born in an empty  box when it has exactly 3 neighbors.\n");
	        printf("2. A cells dies from loneliness if it has fewer than 2 neighbors.\n");
	        printf("3. A cells dies  of overcrowding if it has more than 3 neighbors.\n");
	        printf("4. Otherwise, the cells  survives.\n");
	        printf("\nPlease select the option from Main Menu.\n");
	        printf("\n\t\t:Main Menu:\n");
}
// USE SETSTATE AND GETSTATE FROM FINITESTATEMACHINE TO CONTROL PROGRAM FLOW
