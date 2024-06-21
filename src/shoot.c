/*
** June 2024
** Magdalena Martinez Sanchez
** NAVY_GAME
** shoot.c
*/
#include "../include/navy_game.h"

void shoot_map(map_user_t* map, char* buffer)
{
    int col_pos = get_colrow(buffer[0], 'A', 2);
    int row_pos = get_colrow(buffer[1], '1', 1);
    char impact_pos = map->map[row_pos][col_pos];

    if (impact_pos == '.' || impact_pos == 'o') {
        write_impact('0');
        printf("%s: missed\n", buffer);
        map->map[row_pos][col_pos] = 'o';
    } else {
        write_impact('1');
        printf("%s: hit\n", buffer);
        map->map[row_pos][col_pos] = 'x';
        if (impact_pos != 'x') {
            map->sunken_ships--;
        }
    }
}

void shoot_enemy_map(map_user_t* map, char* buffer, char impact_pos)
{
    int col_pos = get_colrow(buffer[0], 'A', 2);
    int row_pos = get_colrow(buffer[1], '1', 1);
    buffer[2] = '\0';

    if (impact_pos == '0') {
        map->map[row_pos][col_pos] = 'o';
    } else {
        char value_before = map->map[row_pos][col_pos];
        map->map[row_pos][col_pos] = 'x';
        if (value_before != 'x') {
            map->sunken_ships--;
        }
    }
}

void write_impact(char impact)
{
    int fp = open("file_impact.txt", O_WRONLY | O_TRUNC);
    if (fp != -1) {
        write (fp, &impact, sizeof(char));
    }
    close(fp);
}

void read_impact(char *buffer, map_user_t* enemy_map) 
{
    char impact;
    int fp = open("file_impact.txt", O_RDONLY);
    if (fp != -1) {
        read (fp, &impact, sizeof(char));
    }
    close(fp);

    if (impact == '0') {
        printf("%s: missed\n", buffer);
    } else {
        printf("%s: hit\n", buffer);
    }
    shoot_enemy_map(enemy_map, buffer, impact);
}
