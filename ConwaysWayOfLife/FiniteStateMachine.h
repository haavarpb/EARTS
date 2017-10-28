#ifndef FINITESTATEMACHINE_H_
#define FINITESTATEMACHINE_H_

typedef enum {
	INIT,
	MENU,
	GAME,
	QUIT
} state_t;

static state_t state;

void run();

#endif /* FINITESTATEMACHINE_H_ */
