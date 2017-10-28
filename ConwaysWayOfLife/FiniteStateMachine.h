#ifndef FINITESTATEMACHINE_H_
#define FINITESTATEMACHINE_H_

typedef enum {
	INIT,
	MENU,
	GAME,
	QUIT
} state_t;

static state_t state = INIT;

void run();

/* Public functions*/

state_t getState();
void setState(state_t state);


#endif /* FINITESTATEMACHINE_H_ */
