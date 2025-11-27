#include <stdio.h>

#include "structs.h"

#ifndef TESTFUNCS_H_INCLUDED
#define TESTFUNCS_H_INCLUDED

#define SHIPCOUNT 5

#define DIMX 8
#define DIMY 8


void nullmat(int field[DIMX][DIMY]){
    for(int i=0; i<DIMX; i++) {for(int j=0; j<DIMY; j++) {field[i][j] = 0;}}
}
/*
void printm(int field[8][8], int mode) {
    switch(mode){
	case 1: {for(int i=0; i<8; i++) {for(int j=0; j<8; j++) {printf("%d ",field[i][j]);}printf("\n");}break;}
	case 2: {printf("  0 1 2 3 4 5 6 7\n");for(int i=0; i<8; i++){printf("%d ",i);for(int j=0; j<8; j++){printf("%d ",field[j][i]);}printf("\n");}break;}
    default: for(int i=0; i<8; i++) {for(int j=0; j<8; j++){printf("%d",field[i][j]);}printf("\n");}	
    }
}

void printships(Ship *ships){
    for(int i = 0; i < SHIPCOUNT; i++){
        printf("%d %d %d %d\n", ships[i].x, ships[i].y, ships[i].lenght, ships[i].derection);
    }
}

void draw_ships(int field[8][8], Ship *ships){
    for(int i=0; i<SHIPCOUNT; i++){
        switch(ships[i].derection){
            case 0: {for(int j=0; j < ships[i].lenght; j++){field[ships[i].x+j][ships[i].y] = 1;}break;}
            case 1: {for(int j=0; j < ships[i].lenght; j++){field[ships[i].x][ships[i].y+j] = 1;}break;}
        }
    }
}
*/
#endif