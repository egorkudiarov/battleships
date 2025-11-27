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
void generate_start_game(int player_field[DIMX][DIMY], int player_attack_field[DIMX][DIMY], int player_display_field[DIMX][DIMY], 
                         int computer_field[DIMX][DIMY], int computer_attack_field[DIMX][DIMY],  int computer_display_field[DIMX][DIMY], 
                         Ship *player_ships, Ship *computer_ships);
void generate_attack(int *x, int *y, int field[DIMX][DIMY]);

#include "loggers.h"
int game_state_log(char *filename, int *player, int player_field[DIMX][DIMY], int sub_player_field[DIMX][DIMY], Ship *players_ships, Ship *computer_ships);
void game_turn_log(char *filename, int *player, int *x, int *y, int *result);

#include "outputs.h"
void print_boards(int player_field[DIMX][DIMY], int attack_field[DIMX][DIMY]);
void draw_around_ship(int field[DIMX][DIMY], Ship *ships);

#define DIMX 8
#define DIMY 8
#define MAXLEN 5
#define MINLEN 2
#define SHIPCOUNT 5

int turn(int *player_flag, int mode, int x, int y, Ship *ships, int attack_field[DIMX][DIMY], int display_field[DIMX][DIMY]){
    int result = check_attack(x, y, ships, attack_field);
    switch(result){
        case 0:{
            display_field[x][y] = -1;
            break;
        }
        case 1:
            attack_field[x][y] = 2;
            display_field[x][y] = 2;
            break;
            //case 2:
        case 3:{
            attack_field[x][y] = 2;
            display_field[x][y] = 2;
            draw_around_ship(display_field, ships);
            break;
        }
        case 4:{ 
            attack_field[x][y] = 2;
            display_field[x][y] = 2;
            draw_around_ship(display_field, ships);
            break;
        } 
    }
    switch (*player_flag){
        case 0:{ // player
            *player_flag = (mode == 0)?(1):(2);
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
    return result;
}
int main(){
    int win_sum = 0, player_flag = 0, mode;
    char *state_file_name = "state.txt", *log_file_name = "log.txt"; 
    
    int player_field[DIMX][DIMY], player_attack_field[DIMX][DIMY], player_display_field[DIMX][DIMY]; 
    int computer_field[DIMX][DIMY], computer_attack_field[DIMX][DIMY], computer_display_field[DIMX][DIMY];
    Ship player_ships, computer_ships;
    
    generate_start_game(player_field, player_attack_field, player_display_field,
                        computer_field, computer_attack_field, computer_display_field,
                        &player_ships, &computer_ships);
	printf("enter game mode|0 - solo|1 - multy|");
    scanf("%d", &mode);
    print_boards(player_field, player_display_field);
    do{
        int result;
        switch(player_flag){
            case 1:{
                int x, y;
                generate_attack(&x, &y, computer_attack_field);
                result = turn(&player_flag, mode, x, y, &player_ships, computer_attack_field, player_field);
                printf("Computers turn-> x:%d, y:%d\n", x, y);
                print_boards(player_field, player_display_field);
                break;
            }
            default:{
                int x, y;
                printf("Select a coord\n");
                printf("X: ");
                scanf("%d", &x);
                printf("Y: ");
                scanf("%d", &y);
                if((x<0)||(x>SHIPCOUNT)||(y<0)||(x>SHIPCOUNT)){
                    printf("incorrect coords");
                    break;
                }
                result = turn(&player_flag, mode, x, y, &computer_ships, player_attack_field, player_display_field);
                print_boards(player_field, player_display_field);
                break;                
            }
        }
        win_sum += (result == 4)?(1):(0);
    }while (win_sum == 0);
    
    
    return 0;
}
