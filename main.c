#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "structs.h"

#include "checks.h" 
int check_destroyed(int coordx, int coordy, Ship *ships, int field[8][8]);
int check_attack(int x, int y, Ship *ships, int field[8][8]);
int check_overlaps(Ship *ship, Ship *ships, int num);
int check_win(Ship *ships);

#include "testfuncs.h"
void nullmat(int field[DIMX][DIMY]);

#include "generators.h"
void generate_ships(Ship *ships, int num);
void generate_start_game(int player_field[DIMX][DIMY], int player_attack_field[DIMX][DIMY], int computer_field[DIMX][DIMY], int computer_attack_field[DIMX][DIMY],Ship *player_ships, Ship *computer_ships);

#include "loggers.h"
int game_state_log(char *filename, int *player, int player_field[DIMX][DIMY], int sub_player_field[DIMX][DIMY], Ship *players_ships, Ship *computer_ships);
void game_turn_log(char *filename, int *player, int *x, int *y, int *result);

#include "outputs.h"
void print_boards(int player_field[DIMX][DIMY], int attack_field[DIMX][DIMY]);

#define DIMX 8
#define DIMY 8
#define MAXLEN 5
#define MINLEN 2
#define SHIPCOUNT 5

int turn(int *player_flag, int mode, int x, int y, Ship *ships, int field[DIMX][DIMY]){

    switch (*player_flag){
        case 0:{ // player
            *player_flag = (mode != 0)?(2):(1);
            break;
        }
        case 1:{ // computer
            *player_flag = 0;
            break;
        }
        case 2:{ // 2nd player
            *player_flag = 0;
            break;
        }
    }
    //game_state_log();
}
int main(){
    int win_sum = 0, player_flag = 0;

    int player_field[DIMX][DIMY], player_attack_field[DIMX][DIMY], computer_field[DIMX][DIMY], computer_attack_field[DIMX][DIMY];
    Ship player_ships, computer_ships;
    generate_start_game(player_field, player_attack_field, computer_field, computer_attack_field, &player_ships, &computer_ships);
	/*do{
        
        int result = 0;//turn();
        win_sum += result;
    }while (win_sum == 0);
    */
    print_boards(player_field, player_attack_field);
    
    return 0;
}
 