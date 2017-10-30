#include "FiniteStateMachine.h"

state_t state = INIT;

void run(){
	while(1){
		switch(state){
			case INIT :
				initializeWindow();
				printf("HELLO\n");
				instantiateCellArray();
				printHomepage();
				state = MENU;
				continue;
			case MENU :
				choose_presets();
				break;
			case GAME :
				evaluateCells();
				break;
			case QUIT :
				freeCellArray();
				terminateWindow();
				break;
		}
	}
}

/* Public state */

state_t getState(){return state;}
void setState(state_t s){state = s;}
