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
void generate_ships(Ship *ships, int num);
void generate_start_game(int player_field[DIMX][DIMY], int player_attack_field[DIMX][DIMY], int computer_field[DIMX][DIMY], int computer_attack_field[DIMX][DIMY],Ship *player_ships, Ship *computer_ships);


#include "structs.h"

#define DIMX 8
#define DIMY 8
#define MAXLEN 5
#define MINLEN 2
#define SHIPCOUNT 5

void turn(int x, int y, int field[DIMX][DIMY], Ship *ships, int mode){
    static int player_flag = 0;
    switch (player_flag)
    {
    case 0:{ // player


        player_flag = (mode != 0)?(2):(1);
        break;
    }
    case 1:{ // computer

        player_flag = 0;
        break;
    }
    case 2:{ // 2nd player
        
        
        player_flag = 0;
        break;
    }
    default:
        break;
    }
}

int main(){
    int player_field[DIMX][DIMY], player_attack_field[DIMX][DIMY], computer_field[DIMX][DIMY], computer_attack_field[DIMX][DIMY];
    Ship player_ships, computer_ships;
    generate_start_game(player_field, player_attack_field, computer_field, computer_attack_field, &player_ships, &computer_ships);
    printm(player_field, 2);
    printships(&player_ships);
	return 0;
}

 