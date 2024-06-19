/*
** June 2024
** Magdalena Martinez Sanchez
** Project Name
** main.c
*/

#include "../include/navy_game.h"


/* 
    NAVY GAME
    If the player needs help: ./navy_game -h
    If the first player want to connect: ./navy_game 1stPlayerPID
    If the second player want to connect: ./navy_game 1stPlayerPID 2ndPlayerPID
*/


int main(int argc, char **argv) {
    //puede pedir ayuda
    //puede ser el primer jugador
    //puede ser el segundo jugador
    int value = 0;
    if (strcmp(argv[argc - 1], "-h") == 0 && argc < 3) {
        //help
        display_help();
    } else if (argc == 2) {
        printf("PRIMER JUGADOR\n");
        return player_init(argv[argc - 1], 1, 0);
    } else if (argc == 3) {
        printf("SEGUNDO JUGADOR\n");
        return player_init(argv[argc - 1], 2,  argv[argc - 2]);
    }  
    return value; 
}

int player_init(char* filename, int player,  char* pid1)
{
    char buffer[MAX_BUFFER];
    if (open_file(filename, buffer) != -1) {
        if (player == 1) {
            first_player(buffer);
        } else {
            second_player(buffer, pid1);
        }
    }
    return ERROR_EXIT;
}

void display_help(void) {
    printf("USAGE\n"); 
    printf("    ./navy_game [1stPlayerPID] navy_positions\n");
    printf("DESCRIPTION\n");
    printf("     first_player_pid: only for the 2nd player.");
    printf("pid of the first player.\n");
    printf("navy_positions: file representing the positions of ");
    printf("the ships.\n");
}