#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "structs.h"

#include "checks.h"
int check_attack(int x, int y, Ship *ships, int field[8][8]);

#include "testfuncs.h"
void nullmat(int field[DIMX][DIMY]);

#ifndef OUTPUTS_H_INCLUDED
#define OUTPUTS_H_INCLUDED

#define DIMX 8
#define DIMY 8
#define MAXLEN 5
#define MINLEN 2
#define SHIPCOUNT 5


char *char_select(int ch){
    switch (ch){
        case 0: return "~";
        case 1: return "=";
        case 2: return "X";
        default: return "O";
    }
}

void draw_around_ship(int field[DIMX][DIMY], Ship *ships){
    for(int i = 0; i < SHIPCOUNT; i++){
        if((ships[i].is_destroyed == 1)&&(ships[i].is_drawn == 0)){
            ships[i].is_drawn = 1;
            switch(ships[i].derection){
                case 0: {
                    int j = 0;
                    field[ships[i].x-1][ships[i].y-1] = 2;
                    field[ships[i].x-1][ships[i].y+1] = 2;
                    for(j; j < ships[i].lenght; j++){
                        field[ships[i].x+j][ships[i].y-1] = 2;
                        field[ships[i].x+j][ships[i].y+1] = 2;
                    }
                    field[ships[i].x+1][ships[i].y-1] = 2;
                    field[ships[i].x+1][ships[i].y+1] = 2;
                    break;
                }
                case 1: { 
                    int j = 0;
                    field[ships[i].x-1][ships[i].y-1] = 2;
                    field[ships[i].x+1][ships[i].y-1] = 2;
                    for(j; j < ships[i].lenght; j++){
                        field[ships[i].x-1][ships[i].y+j] = 2;
                        field[ships[i].x+1][ships[i].y+j] = 2;
                    }
                    field[ships[i].x-1][ships[i].y+1] = 2;
                    field[ships[i].x+1][ships[i].y+1] = 2;
                    break;
                }
            }   
        }
    }
}

void print_boards(int player_field[DIMX][DIMY], int player_display_field[DIMX][DIMY]){
    printf("  ");
    for(int j=0; j<DIMX; j++){printf("%d ", j);}
    printf("\t");
    printf("  ");
    for(int j=0; j<DIMX; j++){printf("%d ", j);}
    printf("\n");

    for(int i=0; i<DIMY; i++){
        printf("%d ",i);
        for(int j=0; j<DIMX; j++){
            printf("%s ",char_select(player_field[j][i]));
        }
        printf("\t");
        printf("%d ",i);
        for(int j=0; j<DIMX; j++){
            printf("%s ",char_select(player_display_field[j][i]));
        }
        printf("\n");
    }
}


void print_menu(){

}

#endif