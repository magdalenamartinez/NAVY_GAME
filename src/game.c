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
    //Imprimir mapas
    print_map(map);
    print_map(enemy_map);   
    //Player
    if (player == 1) {
        first_player_game(pid, enemypid, map, enemy_map);
    } else {
        second_player_game(pid, enemypid, map, enemy_map);
    }
    free_map(map);
    free_map(enemy_map);
}

void first_player_game(int pid, int enemypid, map_user_t* map, map_user_t* enemy_map)
{
    signal(SIGUSR2, signal_2);

    while (map->sunken_ships > 0 && enemy_map->sunken_ships > 0) {
        attack_enemy(); //ATACA ENEMIGO
        kill(enemypid, SIGUSR1);
        pause();
        read_attack(enemy_map, 1); //LEE ATAQUE AL ENEMIGO
        printf("Waiting for enemy attack...\n");
        kill(enemypid, SIGUSR1);
        pause();
        read_attack(map, 0); //LEE EL ATAQUE DEL ENEMIGO
        print_map(map);
        print_map(enemy_map);
        kill(enemypid, SIGUSR1);
    }

    get_winner(map);
}

void second_player_game(int pid, int enemypid, map_user_t* map, map_user_t* enemy_map)
{
    signal(SIGUSR1, signal_1);
    while (map->sunken_ships > 0 && enemy_map->sunken_ships > 0) {
        printf("Waiting for enemy attack...\n");
        pause();
        read_attack(map, 0); //LEE EL ATAQUE DE ENEMIGO
        kill(enemypid, SIGUSR2);
        pause();
        attack_enemy(); //ATACA ENEMIGO
        kill(enemypid, SIGUSR2);
        pause();
        read_attack(enemy_map, 1); //LEE ATAQUE AL ENEMIGO
        print_map(map);
        print_map(enemy_map);   
        kill(enemypid, SIGUSR2);
    }
    get_winner(map);
}

void get_winner(map_user_t* map) 
{
    if (map->sunken_ships == 0) {
        printf("\nEnemy Won\n");
    } else {
        printf("\nI Won\n");
    }
}

