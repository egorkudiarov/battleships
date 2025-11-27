#include "structs.h"

#ifndef CHECKS_H_INCLUDED
#define CHECKS_H_INCLUDED

#define DIMX 8
#define DIMY 8
#define MAXLEN 5
#define MINLEN 2
#define SHIPCOUNT 5

int check_destroyed(int coordx, int coordy, Ship *ships, int field[8][8]) {
	int is_point_on = 0;
	for(int i=0; i < 5; i++) {
		int sum = 0;
		switch(ships[i].derection) {
		case 0: {
			for(int j=0; j < ships[i].lenght; j++) {
				int y = ships[i].y;
				int x = ships[i].x + j;
				if((coordx == x)&&(coordy == y)) {
					is_point_on = 1;
				}
				sum += field[y][x];
			}
			break;
		}
		case 1: {
			for(int j=0; j < ships[i].lenght; j++) {
				int x = ships[i].x;
				int y = ships[i].y + j;
				if((coordx == x)&&(coordy == y)) {
					is_point_on = 1;
				}
				sum += field[y][x];}
            break;
		}
		if((sum == (ships[i].lenght * 2))&&(is_point_on)) {
			ships[i].is_destroyed = 1;
            return 1;
		}
		if(is_point_on) {
			return 0;
		}
		}
	}
}

int check_attack(int x, int y, Ship *ships, int field[8][8]) {
	if(field[y][x] == 2) {
		return 2; //Already Hit
	}
	if(field[y][x] == 1) {
		field[y][x] = 2;
		if(check_destroyed(x, y, ships, field) == 1) {
            return 3; //Destroyed
        }   
		return 1; //Hit
	} 
	return 0; //Miss
}

int check_overlaps(Ship *ship, Ship *ships, int num){
    if(num == 0){return 0;}
    int sum = 0;
    for(int i=0; i < num; i++){
        int x1 = ship->x, x2 = ships[i].x;
        int y1 = ship->y, y2 = ships[i].y;
        int cooderection = ship->derection + ships[i].derection;
        switch(cooderection){
            case 0: {
                int ydelta = (y1 > y2)?(y1 - y2):(y2 - y1);
                int xdelta = (x1 > x2)?(x1 - (x2 + ships[i].lenght)):(x2 - (x1 + ship->lenght));
                if(((xdelta >= 1)&&(ydelta >= 1))||((xdelta >= 1)&&(ydelta == 0))||(ydelta >= 2)){
                    sum++;
                }
                break;
            }
            case 1: {
                int xdelta, ydelta = 0; 
                if(ship->derection == 0){
                    xdelta = (x2 > x1)?(x2 - x1 - ship->lenght):(x1 - x2 - 1);    
                    ydelta = (y1 > y2)?(y1 - y2 - ships[i].lenght):(y2 - y1 - 1);
                }
                if(ships[i].derection == 0){
                    xdelta = (x1 > x2)?(x1 - x2 - ships[i].lenght):(x2 - x1 - 1);
                    ydelta = (y2 > y1)?(y2 - y1 - ship->lenght):(y1 - y2 - 1);    
                }
                if((xdelta >= 1)||(ydelta >= 1)){
                    sum++;
                }
                break;
            }
            case 2: {
                int xdelta = (x1 > x2)?(x1 - x2):(x2 - x1);
                int ydelta = (y1 > y2)?(y1 - (y2 + ships[i].lenght)):(y2 - (y1 + ship->lenght));
                if(((ydelta >= 1)&&(xdelta >= 1))||((ydelta >= 1)&&(xdelta == 0))||(xdelta >= 2)){
                    sum++;
                }
            }
        }
    }
    return (sum == num)?(0):(1);    
}

int check_win(Ship *ships){
    int sum = 0;
    for(int i = 0; i < SHIPCOUNT; i++){
        sum += (ships[i].is_destroyed != 0)?(1):(0);
    }
    return (sum == SHIPCOUNT)?(1):(0);
}
#endif