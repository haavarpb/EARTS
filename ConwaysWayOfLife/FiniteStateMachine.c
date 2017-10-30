#include "FiniteStateMachine.h"

#include "ConwaysWayOfLife.h"

void run(){
	while(1){
		switch(state){
			case INIT :
				initializeWindow();

				state = MENU;
				break;
			case MENU :
				// Wait for input
				continue;
			case GAME :
				evaluateCells();
				break;
			case QUIT :
				break;
		}
		parseInput(); // MENU FUNCTION
	}
}

/* Public state */

state_t getState(){return state;}
void setState(state_t s){state = s;}
