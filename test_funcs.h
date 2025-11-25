#include <stdio.h>

#ifndef TESI_FUNCS_INCLUDED
#define TESI_FUNCS_INCLUDED

#define SHIPCOUNT 5

void nullmat(int field[8][8]){
    for(int i=0; i<8; i++) {for(int j=0; j<8; j++) {field[i][j] = 0;}}
}

void printm(int field[8][8], int mode) {
    switch(mode){
	case 1: {for(int i=0; i<8; i++) {for(int j=0; j<8; j++) {printf("%d ",field[i][j]);}printf("\n");}break;}
	case 2: {printf("  0 1 2 3 4 5 6 7\n");for(int i=0; i<8; i++){printf("%d ",i);for(int j=0; j<8; j++){printf("%d ",field[j][i]);}printf("\n");}break;}
    default: for(int i=0; i<8; i++) {for(int j=0; j<8; j++){printf("%d",field[i][j]);}printf("\n");}	
    }
}

#endif