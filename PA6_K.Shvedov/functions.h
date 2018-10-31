#ifndef FUNCTIONS_H
#define FUNCTIONS_H


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <ctype.h>
#include <conio.h>

typedef struct boats
{
	//the amount of hits received by each boat
	int carrier;
	int battleship;
	int cruiser;
	int submarine;
	int destroyer;
	//the amount this players ships have sunk
	int ships_sunk;
} Boats;

typedef struct stats
{
	int total_hits;
	int total_misses;
	int total_shots;
	double hits_misses;
} Stats;

void welcome_screen(void);

void select_who_starts_first(int *player);

void manually_place_ships_on_board(char grid[10][10]);

void randomly_place_ships_on_board(char grid[10][10], char player);

void random_coordinates(int *row, int *column, int *compass, int size);

void random_shot(int *row, int *column);

int check_shot(char grid[10][10], int row, int column, Boats *playerboat, Stats *playerstat, FILE *battlelog, char player);

int is_winner(Boats *player);

void final_stats(Stats *player, Stats *machine, FILE *battlelog);

void hit_miss_ratio(Stats *player, Stats *machine);

void random_manual(char grid[10][10]);

void place_ship(int row, int column, char grid[10][10], char boat, char compass, char player);

void reduce(int *row, int *column);

void increase(int *row, int *column);

void clear_screen(void);

int check_if_fits_grid(int row, int column, char compass, int length, char grid[10][10]);

int check_overlap(int row, int column, char compass, int length, char grid[10][10]);

void place_ship(int row, int column, char grid[10][10], char boat, char compass, char player);

int size(char boat);

char ship_type(char boat, char player);

void white_on_black(void);

void water(void);

void miss(void);

void hit(void);

void grid_color(char grid[10][10], int c, int r);

void print_type(char grid[10][10], int c, int r);

void initialize_game_board(char grid[10][10]);

void print_grid(char grid[10][10]);

void one_play(char grid[10][10], char player, Boats *playerboat, Stats *playerstat, FILE *battlelog);

void game_turns(char human[10][10], char machine[10][10], int player, Boats *playerboat, Stats *playerstat, Boats *machineboat, Stats *machinestat, FILE *battlelog);

void initialize_stats(Boats *boats, Stats *stats);

void game(void);
#endif