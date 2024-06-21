/*
** June 2024
** Magdalena Martinez Sanchez
** NAVY_GAME
** attack.c
*/

#include "../include/navy_game.h"

void attack_enemy(void)
{
    char *letter = (char*) malloc(4 * sizeof(char));
    size_t lettersize = 4 * sizeof(char);

    printf("Attack: ");
    getline(&letter, &lettersize, stdin);
    check_attack(letter);
}

void check_attack(char* letter)
{
    if (!is_letter(letter[0]) || strlen(letter) != 3 || !is_number(letter[1])) {
        printf("You have introduced a wrong position\n");
        return;
    } else {
        int fp = open("file_attack.txt", O_WRONLY | O_TRUNC);
        if (fp != -1) {
            write(fp, letter, sizeof(letter));
        }
    }
}

void read_attack(map_user_t* map, int enemy) 
{
    int fp = open("file_attack.txt", O_RDONLY);
    char buffer[4];
    int n = read(fp, buffer, sizeof (buffer));
    buffer[2] = '\0';
    close(fp);
    if (enemy == 1) {
        read_impact(buffer, map);
    } else {
        shoot_map(map, buffer);
    }
}

