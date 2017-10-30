void parseInput(){
	int input = readInput();
	switch((char) input){
	case 'q': // quit the entire game from anywhere
		state = QUIT;
		break;
	case 'r':
	default :
	}
}

// USE SETSTATE AND GETSTATE FROM FINITESTATEMACHINE TO CONTROL PROGRAM FLOW
