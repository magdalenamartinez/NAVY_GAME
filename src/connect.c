/*
** June 2024
** Magdalena Martinez Sanchez
** NAVY_GAME
** connect.c
*/

#include "../include/navy_game.h"

void first_player(char *buffer)
{
    signal(SIGUSR1, signal_1);
    pid_t pid = getpid();

    printf("my_pid: %d\n", pid);
    printf("Waiting for enemy connection...\n");
        
    pause();
    int pid2;
    connect_function(pid, 1, &pid2);
    start_game(pid, pid2, buffer, 1);
}

void second_player(char* buffer, char* pid1char)
{
    signal(SIGUSR2, signal_2);
    pid_t pid = getpid();
    int pid1 = atoi(pid1char);
    printf("my_pid: %d\n", pid);
    connect_function(pid, 2, &pid1);
    pause();
    printf("successfully connected\n");
    start_game(pid, pid1, buffer, 2);
}

void connect_function(int pid, int player_num, int* pidenemy)
{
    int pidkill;
    int signal; 

    int fp;
    if (player_num == 1) {
        fp = open("file_aux.txt", O_RDONLY);
        if (fp == -1) {
            printf("An error has occurred\n");
            return;
        } 
        read(fp, pidenemy, sizeof(int));
        signal = SIGUSR2;
    } else {
        fp = open("file_aux.txt", O_WRONLY | O_TRUNC);
        if (fp == -1) {
            printf("An error has occurred\n");
            return;
        } 
        write(fp, &pid, sizeof(int));
        signal = SIGUSR1;
    }
    close(fp);
    kill(*pidenemy, signal);
}
