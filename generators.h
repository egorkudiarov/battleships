#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "structs.h"

#include "checks.h"
int check_attack(int x, int y, Ship *ships, int field[8][8]);
int check_overlaps(Ship *ship, Ship *ships, int num);

#include "testfuncs.h"
void nullmat(int field[DIMX][DIMY]);

#ifndef GENERATORS_H_INCLUDED
#define GENERATORS_H_INCLUDED

#define DIMX 8
#define DIMY 8
#define MAXLEN 5
#define MINLEN 2
#define SHIPCOUNT 5

void generate_ships(Ship *ships, int num){
    srand(time(NULL));
    int i = 0;
    do{
        Ship temp;
        temp.is_destroyed = 0;
        temp.is_drawn = 0;
        temp.derection = rand()%2;
        temp.lenght = (rand()%(MAXLEN-MINLEN)) + MINLEN;
        switch(temp.derection) {
            case 0:{
                temp.x = rand()%(DIMX-temp.lenght);
                temp.y = rand()%DIMY;
                break;
            }
            case 1:{
                temp.y = rand()%(DIMY-temp.lenght);
                temp.x = rand()%DIMX;
                break;
            }
        } ;
        if(check_overlaps(&temp, ships, i) == 0){
            ships[i] = temp;
            i++;
        }
    }while(i < num+1); 
}

void generate_board(int field[DIMX][DIMY], Ship *ships){
    for(int i=0; i<SHIPCOUNT; i++){
        switch(ships[i].derection){
            case 0: {for(int j=0; j < ships[i].lenght; j++){field[ships[i].x+j][ships[i].y] = 1;}break;}
            case 1: {for(int j=0; j < ships[i].lenght; j++){field[ships[i].x][ships[i].y+j] = 1;}break;}
        }
    }
}

void generate_attack(int *x, int *y, int field[DIMX][DIMY]){
    srand(time(NULL));
    int flag = 0;
    do{
        int i = rand()%DIMX;
        int j = rand()%DIMY;
        if(field[i][j] == 0){
            *x = j;
            *y = i;
            flag = 1;
        };
    }while(flag == 0);
}

void generate_start_game(int player_field[DIMX][DIMY], int player_attack_field[DIMX][DIMY], int player_display_field[DIMX][DIMY], 
                         int computer_field[DIMX][DIMY], int computer_attack_field[DIMX][DIMY], int computer_display_field[DIMX][DIMY],
                         Ship *player_ships, Ship *computer_ships){
        nullmat(player_field);  
        nullmat(player_attack_field);
        nullmat(player_display_field);
        nullmat(computer_field); 
        nullmat(computer_attack_field);
        nullmat(computer_display_field);
        generate_ships(player_ships, SHIPCOUNT);
        generate_ships(computer_ships, SHIPCOUNT);
        generate_board(player_field, player_ships);  
        generate_board(player_attack_field, computer_ships);
        generate_board(computer_field, player_ships); 
        generate_board(computer_attack_field, computer_ships);
        
}
#endif