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
void draw_ships(int field[8][8], Ship *ships);

#include "generators.h"
void generate_ships(int field[8][8], Ship *ships, int num);

#include "structs.h"

#define DIMX 8
#define DIMY 8
#define MAXLEN 5
#define MINLEN 2
#define SHIPCOUNT 5


int main() {
    int field[8][8];
    Ship ships[5];
    generate_ships(field, ships, SHIPCOUNT);
    nullmat(field);
    draw_ships(field, ships);
    printm(field, 2);
    printships(ships);
	return 0;
}

 