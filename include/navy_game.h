/*
** June 2024
** Magdalena Martinez Sanchez
** NAVY_GAME
** navy_game.h
*/
#ifndef NAVY_GAME_H_
    #define NAVY_GAME_H_
    #define ERROR_EXIT 84
    #define MAX_BUFFER 2000000
    #include <stdio.h>
    #include <string.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <ctype.h>
    #include <signal.h>

    typedef struct map_user {
        char** map;
        int rows;
        int cols;
        int sunken_ships;
    } map_user_t;

    /*main.c*/
    int player_init(char* filename, int player, char* pid1);
    void display_help(void);
    /*file.c*/
    int open_file(char* filename, char* buffer);
    int read_file(int fp, char* buffer); 
    int check_buffer(char* buffer);
    int check_line(int i, char* buffer);
    int check_third_pos(char character, int i, int j);
    /*signal.c*/
    void signal_1(int signum);
    void signal_2(int signum);
    /*connect.c*/
    void first_player(char *buffer);
    void second_player(char* buffer, char* pid1char);
    void connect_function(int pid, int player_num, int* pid1);
    /*map.c*/
    map_user_t* create_new_map(void); 
    void init_map(map_user_t* new_map);
    void print_map(map_user_t* map);
    void write_map(map_user_t* map, char* buffer);
    /*game.c*/
    void start_game(int pid, int enemypid, char* buffer, int player); 
    void first_player_game(int pid, int enemypid, map_user_t* map, map_user_t* enemy_map);
    void second_player_game(int pid, int enemypid, map_user_t* map, map_user_t* enemy_map);
    void get_winner(map_user_t* map);
    /*boat.c*/
    void read_boat(map_user_t* map, char* buffer, int i);
    int get_colrow(char value, char current_value, int j);
    void draw_boat(map_user_t* map, int row_pos, int col_pos, int size, char orientation);
    /*utilities.c*/
    int is_number(char letter);
    int is_letter(char letter);
    /*attack.c*/
    void check_attack(char* letter);
    void attack_enemy(void);
#endif /*NAVY_GAME_H_*/