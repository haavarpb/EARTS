#include "FiniteStateMachine.h"

#include "ConwaysWayOfLife.h"

void run(){
	while(1){
		switch(state){
			case INIT :
				break;
			case MENU :
				break;
			case GAME :
				evaluateCells();
				break;
			case QUIT :
				break;
		}
		parseInput();
	}
}

/* Public state */

state_t getState(){return state;}
void setState(state_t s){state = s;}
