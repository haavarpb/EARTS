#include "FiniteStateMachine.h"
#include "ConwaysWayOfLife.h"

void run(){
	while(1){
		switch(state){
			case INIT :
				initializeWindow();
				instantiateCellArray();
				printLogo();
				sleep(1);
				state = MENU;
				continue;
			case MENU :
				parseInput();
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
