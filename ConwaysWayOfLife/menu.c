#include "menu.h"
#include <unistd.h>

// CODER 1

void printHomepage(){
   writeTextToScreen("GAME OF LIFE");
}

void choose_presets(){
	mvprintw(1,0, "Presets \n a =  R-Pentomino \n b = dieHard \n c = Acorn");
    cellArrayPresets_t preset;
    char char_presets = getch();
    if (char_presets == 'a'){
        preset = e_rPentomino;
    }
    else if (char_presets == 'b'){
       	preset = e_dieHard;
    }
	else if (char_presets == 'c'){
		preset = e_acorn;
    }
    insertPreset(preset);
    setState(GAME);
   }
