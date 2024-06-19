/*
** June 2024
** Magdalena Martinez Sanchez
** NAVY_GAME
** file.c
*/

#include "../include/navy_game.h"

int open_file(char* filename, char* buffer) 
{
    int fp = open(filename, O_RDONLY);
    if (fp != -1) {
        return read_file(fp, buffer);
    }
    return ERROR_EXIT;
}

int read_file(int fp, char* buffer) 
{
    int length = 0;
    int offset = 0;
    while ((length = read(fp, buffer + offset, MAX_BUFFER - offset)) > 0) {
        offset += length;
    }
    buffer[offset] = '\0';
    close(fp);
    return check_buffer(buffer);
}

int check_buffer(char* buffer)
{
    int i = 0;
    int iteration = 0;
    while (i != -1 && iteration <= 4 && buffer[i] != '\0') {
        if (isdigit(buffer[i]) && buffer[i + 1] == ':') {
            i = check_line(i + 2, buffer);
            iteration++;
        }
    }
    if (i != -1 && iteration <= 4) {
        return 0;
    }
    return -1;
}

int check_line(int i, char* buffer) 
{
    int j = i;
    while (j < i + 4 && j != -1) {
        if (is_letter(buffer[j]) && isdigit(buffer[j + 1]) && check_third_pos(buffer[j + 2], i, j)) {
            j += 3;
        } else {
            j = -1;
        }
    }
    if (j != -1) {
        return j;
    } 
    return -1;
}

int check_third_pos(char character, int i, int j)
{
    if (character == ':' && i == j) {
        return 1;
    } else if ((character == '\n' || character == '\0') && j > i) {
        return 1;
    } 
    return 0;
}

int is_letter(char letter) 
{
    if (letter > 64 && letter < 73) {
        return 1;
    }
    return 0;
}
