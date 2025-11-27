#include <stdio.h>
#include <stdlib.h>

#include "structs.h"

#ifndef LOGGERS_H_INCLUDED
#define LOGGERS_H_INCLUDED

#define DIMX 8
#define DIMY 8
#define MAXLEN 5
#define MINLEN 2
#define SHIPCOUNT 5

void ships_write(FILE *file, Ship *ships){
    for(int i = 0; i < SHIPCOUNT; i++){
        printf("%d %d %d %d %d\n", ships[i].x, ships[i].y, ships[i].lenght, ships[i].derection, ships[i].is_destroyed);
    }
}

void board_copy(FILE *main, FILE *temp){
    char line[DIMX+1];
    for(int i = 0; i < (DIMX*2); i++){
        fscanf(main, "%s", &line);
        fprintf(temp, "%s\n", line);
    }
}

void board_write(FILE *main, FILE *temp, int player_field[DIMX][DIMY], int sub_player_field[DIMX][DIMY]){
    char line[DIMX+1];
    for(int i = 0; i < DIMY; i++){
        for(int j = 0; i < DIMX; i++){
            fprintf(temp, "%d",player_field[i][j]);
        }
        fscanf(main, "%s", &line);
        fprintf(temp, "\n");
    }
    for(int i = 0; i < DIMY; i++){
        for(int j = 0; i < DIMX; i++){
            fprintf(temp, "%d",sub_player_field[i][j]);
        }
        fscanf(main, "%s", &line);
        fprintf(temp, "\n");
    }
}


int game_state_log(char *filename, int *player, int player_field[DIMX][DIMY], int sub_player_field[DIMX][DIMY], Ship *players_ships, Ship *computer_ships){
    FILE *temp, *main;
    temp = fopen("temp.txt", "w");
    main = fopen(filename, "r");
    switch(*player){
        case (0):{
            board_copy(main, temp);
            board_write(main, temp, player_field, sub_player_field);
            break;
        }
        case (1):{
            board_write(main, temp, player_field, sub_player_field);
            board_copy(main, temp);
            break;
        }
        default: return 1;
    }
    fclose(temp);
    fclose(main);
    temp = fopen("temp.txt", "r");
    main = fopen(filename, "w");
    board_copy(temp, main);  
    board_copy(temp, main);  
    ships_write(main, players_ships);
    ships_write(main, computer_ships);
    fclose(temp);
    fclose(main);
    return 0;
}

void game_turn_log(char *filename, int *player, int *x, int *y, int *result){
    FILE *file;    
    file = fopen(filename, "a");
    fprintf(file, "%d|%d %d|%d", player, x, y, result);
    fclose(file);
}
#endif