#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "checks.h" 
int check_destroyed(int coordx, int coordy, Ship *ships, int field[8][8]);
int check_attack(int x, int y, Ship *ships, int field[8][8]);
int check_overlaps(Ship *ship, Ship *ships, int num);

#include "testfuncs.h"
void nullmat(int field[8][8]);
void printm(int field[8][8], int mode);
void printships(Ship *ships);

#include "structs.h"

#define DIMX 8
#define DIMY 8
#define MAXLEN 5
#define MINLEN 2
#define SHIPCOUNT 5
 
int test_field[8][8] = {
	{0,0,0,0,0,0,0,0},
	{0,1,0,1,1,1,1,0},
	{0,1,0,0,0,0,0,0},
	{0,1,0,0,1,0,0,1},
	{0,0,0,0,1,0,0,1},
	{0,1,1,0,1,0,0,1},
	{0,0,0,0,1,0,0,1},
	{0,0,0,0,0,0,0,1}
};
 
int test_vectors[8][5] = {
	{1,1,3,1,0},
	{3,1,4,0,0},
	{4,3,4,1,0},
	{5,1,2,0,0},
	{7,3,5,1,0}
};

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
            }
        } ;
        if(check_overlaps(&temp, ships, i) == 0){
            ships[i] = temp;
            i++;
        }
    }while(i < num);
 
}

void draw_ships(int field[8][8], Ship *ships){
    for(int i=0; i<SHIPCOUNT; i++){
        switch(ships[i].derection){
            case 0: {for(int j=0; j < ships[i].lenght; j++){field[ships[i].x+j][ships[i].y] = 1;}break;}
            case 1: {for(int j=0; j < ships[i].lenght; j++){field[ships[i].x][ships[i].y+j] = 1;}}
        }
    }
}
 

int main() {
	Ship test_ships[5];
	for(int i=0; i < 5; i++) {
		Ship temp;
		temp.x = test_vectors[i][0];
		temp.y = test_vectors[i][1];
		temp.lenght = test_vectors[i][2];
		temp.derection = test_vectors[i][3];
		temp.is_destroed = test_vectors[i][4];
		test_ships[i] = temp;
	}
	    int field[8][8];
	    Ship ships[5];
	    generate_ships(field, ships, SHIPCOUNT);
	    nullmat(field);
	    draw_ships(field, ships);
	    printm(field, 2);
        printships(ships);
	return 0;
}

 