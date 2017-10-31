#include "menu.h"
#include <unistd.h>

void printHomepage(){
   char *homepage = "##################\n @= GAME OF LIFE =@\n ##################\n\n" \
		   " -Welcome to Game Of Life- \n\n Rules Of The Game: \n 1. A cell is born in an empty" \
		   "box when it has exactly 3 neighbors.\n 2. A cells dies from loneliness if it has fewer" \
		   "than 2 neighbors.\n 3. A cell dies  of overcrowding if it has more than 3 neighbors.\n" \
		   "4. Otherwise, the cells  survives.\n\nPlease select the option from Main Menu.\n\nMenu:\n" \
		   "\n   c = Choose the presets \n\n q = Exit the Game";
   writeTextToScreen("Hey");
}

void choose_presets(){
    char choice = getch();
    cellArrayPresets_t preset;
    if (choice == 'c') {
    	//char parameters[] = "\nThe Game is starting\n Choice your presets \n a =  R-Pentomino \n b = dieHard \n c = Acorn";

        char char_presets = getch();
        if (char_presets == 'a'){
        	preset = e_rPentomino;
        }
        else if  (char_presets == 'b'){
        	preset = e_dieHard;
        }
		else{
		    preset = e_acorn;
        }
        insertPreset(preset);
        setState(GAME);
    }
}
