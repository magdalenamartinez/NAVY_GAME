/*
** June 2024
** Magdalena Martinez Sanchez
** NAVY_GAME
** utilities.c
*/

#include "../include/navy_game.h"

int is_letter(char letter) 
{
    if (letter > 64 && letter < 73) {
        return 1;
    }
    return 0;
}


int is_number(char letter) 
{
    if (letter > 48 && letter < 57) {
        return 1;
    }
    return 0;
}