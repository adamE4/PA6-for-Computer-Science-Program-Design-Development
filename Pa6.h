#ifndef PA6_H
#define PA6_H
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#define MAX_ROWS 10
#define MAX_COLS 10
#define CARRIER_LENGTH 5
#define BATTLESHIP_LENGTH 4
#define SUBMARINE_LENGTH 3
#define CRUISER_LENGTH 3
#define DESTROYER_LENGTH 2
typedef enum dir
{
	HORIZ, VERT
} Dir;
typedef enum stats
{
	hits,
	misses,
	percetnage,
	win,lose,

}stats;

void welcome_screen();
void init_board(char board[][MAX_COLS], int num_rows, int num_cols);
void print_board(char board[][MAX_COLS], int num_rows, int num_cols);
int who_starts(int num);
int function();
int manually_place_ships_on_board(char p1_board[][MAX_COLS], int ship_lengths[5], char ship_symbols[5], int j);
Dir gen_direction(void);
int generateStartingPoint(char board[][MAX_COLS], int num_rows, int num_cols, int ship_lengths[5], char ship_symbols[5], Dir direction,
	int row_start, int col_start,int j);
int p2_shoot(FILE* outputfile,char p1_board[][MAX_COLS], int* p2_hits, int* p2_misses);
int p1_shot(FILE* outputfile, char p2_board[][MAX_COLS], char shot_board[][MAX_COLS], int* p1_hits, int* p1_misses);
int sunk_ship(char board[][MAX_COLS], int num_rows, int num_cols, int ship_lengths[5], char ship_symbols[5], Dir direction,
	int row_start, int col_start);


#endif
