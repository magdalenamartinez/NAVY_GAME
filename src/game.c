/*
** June 2024
** Magdalena Martinez Sanchez
** NAVY_GAME
** game.c
*/

#include "../include/navy_game.h"

void start_game(int pid, int enemypid, char* buffer, int player) 
{
    //New Map
    map_user_t* map = create_new_map();
    map_user_t* enemy_map = create_new_map();
    //Init Map
    init_map(map);
    init_map(enemy_map);
    //Write Data in Map
    write_map(map, buffer);
    print_map(map);
}