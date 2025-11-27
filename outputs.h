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


void print_boards(int player_field[DIMX][DIMY], int attack_field[DIMX][DIMY]){
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
            printf("%s ",char_select(attack_field[j][i]));
        }
        printf("\n");
    }
}


void print_menu(){

}

#endif