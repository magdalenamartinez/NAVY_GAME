/*
** June 2024
** Magdalena Martinez Sanchez
** NAVY_GAME
** map.c
*/

#include "../include/navy_game.h"

map_user_t* create_new_map(void) 
{
    int i = 0;

    map_user_t* new_map = (map_user_t*) malloc(sizeof(map_user_t));
    new_map->map = malloc(sizeof(char*) * 10);
    new_map->rows = 10;
    new_map->cols = 18;
    new_map->sunken_ships = 14;

    while (i < new_map->rows) {
        new_map->map[i] = malloc(sizeof(char) * new_map->cols);
        i++;
    }
    return new_map;
}

void init_map(map_user_t* new_map) 
{
    int i = 0;
    int j = 0;
    char num = '1';
    
    new_map->map[i++] = " |A B C D E F G H\n\0";
    new_map->map[i++] = "-+---------------\n\0";
 
    while (i < new_map->rows) {
        new_map->map[i][j++] = num++;
        new_map->map[i][j++] = '|';
        while (j < new_map->cols) {
            new_map->map[i][j++] = '.';
            new_map->map[i][j++] = ' ';
        }
        new_map->map[i][j++] = '\n';
        new_map->map[i][j] = '\0';
        j = 0;
        i++;
    }

}

void print_map(map_user_t* map)
{
    int i = 0; int j = 0;
    while (map->map[i] != NULL) {
        while (map->map[i][j] != '\0') {
            printf("%c", map->map[i][j]);
            j++;
        }
        j = 0; i++;
    }
    printf("\n");
}

void write_map(map_user_t* map, char* buffer)
{
    int iteration = 0;
    int i = 0;
    while (iteration < 4) {
        read_boat(map, buffer, i);
        iteration++;
        i += 8;
    }
}

void free_map(map_user_t* map) {
    if (map == NULL) {
        return;
    }
    free(map->map);
    free(map);
}


