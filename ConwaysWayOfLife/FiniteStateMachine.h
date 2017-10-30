#ifndef FINITESTATEMACHINE_H_
#define FINITESTATEMACHINE_H_

#include "menu.h"

typedef enum {
	INIT,
	MENU,
	GAME,
	QUIT
} state_t;

extern state_t state;

void run();

/* Public functions*/

state_t getState();
void setState(state_t state);


#endif /* FINITESTATEMACHINE_H_ */
