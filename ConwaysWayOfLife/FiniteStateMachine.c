#include "FiniteStateMachine.h"

// CODER 3

state_t state = INIT;

void run(){
	while(1){
		switch(state){
			case INIT :
				initializeWindow();
				instantiateCellArray();
				printHomepage();
				state = MENU;
				continue;
			case MENU :
				choose_presets();
				break;
			case GAME :
				evaluate();
				sleep(1);
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
