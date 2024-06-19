/*
** June 2024
** Magdalena Martinez Sanchez
** NAVY_GAME
** boat.c
*/
#include "../include/navy_game.h"

void read_boat(map_user_t* map, char* buffer, int i)
{
    int size = buffer[i] - '0';
    char orientation = 'V';
    //Get column and row
    int col_pos = get_colrow(buffer[i + 2], 'A', 2);
    int row_pos = get_colrow(buffer[i + 3], '1', 1);
    //Check orientation
    if (buffer[i + 3] == buffer[i + 6]) {
        orientation = 'H';
    }
    draw_boat(map, row_pos, col_pos, size, orientation);
}

int get_colrow(char value, char current_value, int j) 
{
    int current_pos = 2;
    while(value != current_value) {
        current_pos += j;
        current_value++;
    }
    return current_pos;
}

void draw_boat(map_user_t* map, int row_pos, int col_pos, int size, char orientation)
{
    int i = 0;
    char char_size = size + '0';

    while (i < size) {
        map->map[row_pos][col_pos] = char_size;
        if (orientation == 'H') {
            col_pos += 2;
        } else {
            row_pos++;
        }
        i++;
    }
}


