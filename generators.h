#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "structs.h"

#include "checks.h"
int check_attack(int x, int y, Ship *ships, int field[8][8]);

#ifndef GENERATORS_H_INCLUDED
#define GENERATORS_H_INCLUDED

#define DIMX 8
#define DIMY 8
#define MAXLEN 5
#define MINLEN 2
#define SHIPCOUNT 5

void generate_ships(int field[8][8], Ship *ships, int num){
    srand(time(NULL));
    int i = 0;
    do{
        Ship temp;
        temp.is_destroed = 0;
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
    }while(i < num); 
}

void generate_board(int field[8][8], Ship ships){
    
}
#endif