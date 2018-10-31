#include "functions.h"

/*
Function: void welcome_screen(void)
Date Created : 3 / 27 / 2017
Date Last Modified : 4 / 02 / 2017
Description : this function is in charge of welcoming player and printing the game rules
Input parameters : None
Returns : None
Precondition : Call function
Postconditions : None
*/
void welcome_screen(void)
{
	printf("***** Welcome to Battleship!*****\n\n");
	printf("Rules of the Game:\n\n");
	printf("1. This is a two player game.\n\n");
	printf("2. Player1 is you and Player2 is the computer.\n\n");
	printf("3. This game is turn based, and the player that goes first is randomly selected.\n\n");
	printf("4. In the first phase the players choose positions for their ships.\n\n");
	printf("5. In phase 2 the game, the players go one at a time trying to find where the ships are placed on the opponents bored\n\n");
	printf("6. Each turn the player is given a random choice of choosing where he wants to shoot\n\n");
	printf("7. The main objective of the game is to find all ships and sink them\n\n");
	printf("8. Game ends only when all the ships sink\n\n");
	clear_screen();
}

/*
Function: void select_who_starts_first(int *player)
Date Created : 3 / 27 / 2017
Date Last Modified : 4 / 02 / 2017
Description : This function is in charge of choosing who goes first, and printing that disition to the screen;
Input parameters : int *player
Returns : None
Precondition : Call function
Postconditions : None
*/
void select_who_starts_first(int *player)
{
	*player = rand() % 2 + 1;
	if (*player == 1)
	{
		printf("THE HUMAN HAS BEEN RANDOMLY CHOSEN TO GO FIRST\n\n");
	}
	else
	{
		printf("THE MACHINE IS NOW THE CHOSEN ONE, IT GOES FIRST!\n\n");
	}
}

/*
Function: void random_manual(char grid[10][10])
Date Created : 3 / 27 / 2017
Date Last Modified : 4 / 02 / 2017
Description : This function is in charge of either helping the player place their ships on board
or randomly placing them for him, depending on what he wants.
Input parameters : char grid[10][10]
Returns : None
Precondition : Call function
Postconditions : None
*/
void random_manual(char grid[10][10])
{
	char select = '\0';
	printf("Would you like to place your ships manually on the board, or have them spawned randomly(m or r): ");
	select = getchar();
	while ('\n' != getchar());
	printf("\n");
	while (select != 'm' && select != 'M' && select != 'r' && select != 'R')
	{
		printf("Invalid selection, please choose again: ");
		select = getchar();
		while ('\n' != getchar());
		printf("\n");
	}
	if (select == 'm' || select == 'M')
	{
		manually_place_ships_on_board(grid);
	}
	else
	{
		randomly_place_ships_on_board(grid, 'h');
	}
}

/*
Function: void manually_place_ships_on_board(char grid[10][10])
Date Created : 3 / 27 / 2017
Date Last Modified : 4 / 02 / 2017
Description : This function is in charge of helping the player place all ships on their board,
it asks for quardinates and if the ship should point down or right from there,
checks if thats possible
Input parameters : char grid[10][10]
Returns : None
Precondition : Call function
Postconditions : None
*/
void manually_place_ships_on_board(char grid[10][10])
{
	int row = 0, column = 0;
	char compass = '\0';
	//prints grid for user convinience
	print_grid(grid);
	printf("Dear player, please choose first coordinate for your carrier ship (5 spaces) and\ndirection it will point from there d or r(row column (down or right), e.g. 3 2 r): ");
	scanf("%d %d ", &row, &column);
	compass = getchar();
	//turns values into form that can be worked with
	reduce(&row, &column);
	//checks if the placement is possible
	while (check_if_fits_grid(row, column, compass, 5, grid) == 0)
	{
		printf("It is not possible to place the boat there, please choose another position: ");
		scanf("%d %d ", &row, &column);
		compass = getchar();
		reduce(&row, &column);
	}
	//places ship
	place_ship(row, column, grid, 'c', compass, 'h');
	clear_screen();
	row = 0;
	column = 0;
	compass = '\0';
	//repeats on from here but for different ships
	print_grid(grid);
	printf("Dear player, please choose first coordinate for your battle ship (4 spaces) and\ndirection it will point from there d or r(row column (down or right), e.g. 3 2 r): ");
	scanf("%d %d ", &row, &column);
	compass = getchar();
	reduce(&row, &column);
	while (check_if_fits_grid(row, column, compass, 4, grid) == 0)
	{
		printf("It is not possible to place the boat there, please choose another position: ");
		scanf("%d %d ", &row, &column);
		compass = getchar();
		reduce(&row, &column);
	}
	place_ship(row, column, grid, 'b', compass, 'h');
	clear_screen();
	row = 0;
	column = 0;
	compass = '\0';
	print_grid(grid);
	printf("Dear player, please choose first coordinate for your cruiser ship (3 spaces) and\ndirection it will point from there d or r(row column (down or right), e.g. 3 2 r): ");
	scanf("%d %d ", &row, &column);
	compass = getchar();
	reduce(&row, &column);
	while (check_if_fits_grid(row, column, compass, 3, grid) == 0)
	{
		printf("It is not possible to place the boat there, please choose another position: ");
		scanf("%d %d ", &row, &column);
		compass = getchar();
		reduce(&row, &column);
	}
	place_ship(row, column, grid, 'r', compass, 'h');
	clear_screen();
	row = 0;
	column = 0;
	compass = '\0';
	print_grid(grid);
	printf("Dear player, please choose first coordinate for your submarine ship (3 spaces) and\ndirection it will point from there d or r(row column (down or right), e.g. 3 2 r): ");
	scanf("%d %d ", &row, &column);
	compass = getchar();
	reduce(&row, &column);
	while (check_if_fits_grid(row, column, compass, 3, grid) == 0)
	{
		printf("It is not possible to place the boat there, please choose another position: ");
		scanf("%d %d ", &row, &column);
		compass = getchar();
		reduce(&row, &column);
	}
	place_ship(row, column, grid, 's', compass, 'h');
	clear_screen();
	row = 0;
	column = 0;
	compass = '\0';
	print_grid(grid);
	printf("Dear player, please choose first coordinate for your destroyer ship (2 spaces) and\ndirection it will point from there d or r(row column (down or right), e.g. 3 2 r): ");
	scanf("%d %d ", &row, &column);
	compass = getchar();
	reduce(&row, &column);
	while (check_if_fits_grid(row, column, compass, 5, grid) == 0)
	{
		printf("It is not possible to place the boat there, please choose another position: ");
		scanf("%d %d ", &row, &column);
		compass = getchar();
		reduce(&row, &column);
	}
	place_ship(row, column, grid, 'd', compass, 'h');
	clear_screen();
}

/*
Function: void randomly_place_ships_on_board(char grid[10][10], char player)
Date Created : 3 / 27 / 2017
Date Last Modified : 4 / 02 / 2017
Description : This function is in charge of randomly placing ships on board with no overlaps,
it also prints different characters(upper case machine, lower case human) depending on who this function is used with,
human or machine
Input parameters : char grid[10][10], char player
Returns : None
Precondition : Call function
Postconditions : None
*/
void randomly_place_ships_on_board(char grid[10][10], char player)
{
	int row = 0, column = 0, comp = 0;
	char compass = '\0';
	do
	{
		//randomizes coordinates and direction
		random_coordinates(&row, &column, &comp, 5);
		if (comp == 1)
		{
			compass = 'd';
		}
		else
		{
			compass = 'r';
		}
		//checks if possible
	} while (check_if_fits_grid(row, column, compass, 5, grid) == 0);
	//places ship on board
	place_ship(row, column, grid, 'c', compass, player);
	//repeats
	do
	{
		random_coordinates(&row, &column, &comp, 4);
		if (comp == 1)
		{
			compass = 'd';
		}
		else
		{
			compass = 'r';
		}
	} while (check_if_fits_grid(row, column, compass, 4, grid) == 0);
	place_ship(row, column, grid, 'b', compass, player);

	do
	{
		random_coordinates(&row, &column, &comp, 3);
		if (comp == 1)
		{
			compass = 'd';
		}
		else
		{
			compass = 'r';
		}
	} while (check_if_fits_grid(row, column, compass, 3, grid) == 0);
	place_ship(row, column, grid, 'r', compass, player);

	do
	{
		random_coordinates(&row, &column, &comp, 3);
		if (comp == 1)
		{
			compass = 'd';
		}
		else
		{
			compass = 'r';
		}
	} while (check_if_fits_grid(row, column, compass, 3, grid) == 0);
	place_ship(row, column, grid, 's', compass, player);

	do
	{
		random_coordinates(&row, &column, &comp, 2);
		if (comp == 1)
		{
			compass = 'd';
		}
		else
		{
			compass = 'r';
		}
	} while (check_if_fits_grid(row, column, compass, 2, grid) == 0);
	place_ship(row, column, grid, 'd', compass, player);
}

/*
Function: void random_coordinates(int *row, int *column, int *compass, int size)
Date Created : 3 / 27 / 2017
Date Last Modified : 4 / 02 / 2017
Description : This function is in charge of randomizing the row, column and compass(down or right) values
Input parameters : int *row, int *column, int *compass, int size
Returns : None
Precondition : Call function
Postconditions : None
*/
void random_coordinates(int *row, int *column, int *compass, int size)
{
	*row = rand() % (10 - size);
	*column = rand() % (10 - size);
	*compass = rand() % 2;
}

/*
Function: void random_shot(int *row, int *column)
Date Created : 3 / 27 / 2017
Date Last Modified : 4 / 02 / 2017
Description : This function is in charge of randomizing the row, column values for the machine to take random shot
Input parameters : int *row, int *column, int *compass
Returns : None
Precondition : Call function
Postconditions : None
*/
void random_shot(int *row, int *column)
{
	*row = rand() % 10;
	*column = rand() % 10;
}

/*
Function: int check_shot(char grid[10][10], int row, int column, Boats *playerboat, Stats *playerstat, FILE *battlelog, char player)
Date Created : 3 / 27 / 2017
Date Last Modified : 4 / 02 / 2017
Description : This function is in charge of checking if the shot hit anything and returning a value of -1, if its a miss. It also checks what is hit
and depending on that prints information to screen and log file. Also edits information for stats for the player and the information about
the aponents boats if any of them are hit. If on is sunk, it says prints so to screen and file.
Input parameters : char grid[10][10], int row, int column, Boats *playerboat, Stats *playerstat, FILE *battlelog, char player
Returns : int if value if shot is possible or not
Precondition : Call function
Postconditions : None
*/
int check_shot(char grid[10][10], int row, int column, Boats *playerboat, Stats *playerstat, FILE *battlelog, char player)
{
	char target = grid[row][column];
	//check if its a valid coordinate
	if (row < 0 || row >= 10 || column < 0 || column >= 10)
	{
		return -1;
	}
	//if its water
	if (target == '-')
	{
		grid[row][column] = 'm';
		//adds one to shots and misses in the stats file
		playerstat->total_misses += 1;
		playerstat->total_shots += 1;
		//transforms coordinates into what the player is used to
		increase(&row, &column);
		//if machine, prints what machine selected
		if (player == 'm')
		{
			printf("Machine Selects: %d,%d\n\n", row, column);
		}
		//prints out the coordinates and thats its a miss
		printf("%d,%d is a miss\n", row, column);
		//chooses what to print to log file depending if human or machine
		if (player == 'h')
		{
			fprintf(battlelog, "Player 1");
		}
		else
		{
			fprintf(battlelog, "Player 2");
		}
		//prints coordinates and that its a miss to a file
		fprintf(battlelog, ": %d,%d \"miss\"\n", row, column);
		return 0;
	}
	//if the selected target has already bean used returns -1
	else if (target == 'm' || target == '*')
	{
		return -1;
	}
	else
	{
		//all of these are almost identical to the miss fial, but edit information related to hit and which boat
		if (target == 'c' || target == 'C')
		{
			grid[row][column] = '*';
			//edits information about hits on boat, hti and total shots
			playerboat->carrier += 1;
			playerstat->total_hits += 1;
			playerstat->total_shots += 1;
			//makes the information into the format the human is used to
			increase(&row, &column);
			if (player == 'm')
			{
				printf("Machine Selects: %d,%d\n\n", row, column);
			}
			//prints to screen that the coordinate is a hit
			printf("%d,%d is a hit\n", row, column);
			//depedning on parameters chooses about what player this information is
			if (player == 'h')
			{
				fprintf(battlelog, "Player 1");
			}
			else
			{
				fprintf(battlelog, "Player 2");
			}
			//prints to file that its a hit
			fprintf(battlelog, ": %d,%d \"hit\"", row, column);
			//prints to screen and log file that the boat has been sunk
			if (playerboat->carrier == 5)
			{
				printf("The Carrier Has Been Sunk!\n");
				fprintf(battlelog, " Sunk Carrier!");
				playerboat->ships_sunk += 1;
			}
			printf("\n");
			fprintf(battlelog, "\n");
			return 1;
		}
		//process repeated for each boat
		else if (target == 'b' || target == 'B')
		{
			grid[row][column] = '*';
			playerboat->battleship += 1;
			playerstat->total_hits += 1;
			playerstat->total_shots += 1;
			increase(&row, &column);
			if (player == 'm')
			{
				printf("Machine Selects: %d,%d\n\n", row, column);
			}
			printf("%d,%d is a hit\n", row, column);
			if (player == 'h')
			{
				fprintf(battlelog, "Player 1");
			}
			else
			{
				fprintf(battlelog, "Player 2");
			}
			fprintf(battlelog, ": %d,%d \"hit\"", row, column);
			if (playerboat->battleship == 4)
			{
				printf("The Battleship Has Been Sunk!\n");
				fprintf(battlelog, " Sunk Battleship!");
				playerboat->ships_sunk += 1;
			}
			printf("\n");
			fprintf(battlelog, "\n");
			return 1;
		}
		else if (target == 'r' || target == 'R')
		{
			grid[row][column] = '*';
			playerboat->cruiser += 1;
			playerstat->total_hits += 1;
			playerstat->total_shots += 1;
			increase(&row, &column);
			if (player == 'm')
			{
				printf("Machine Selects: %d,%d\n\n", row, column);
			}
			printf("%d,%d is a hit\n", row, column);
			if (player == 'h')
			{
				fprintf(battlelog, "Player 1");
			}
			else
			{
				fprintf(battlelog, "Player 2");
			}
			fprintf(battlelog, ": %d,%d \"hit\"", row, column);
			if (playerboat->cruiser == 3)
			{
				printf("The Cruiser Has Been Sunk!\n");
				fprintf(battlelog, " Sunk Cruiser!");
				playerboat->ships_sunk += 1;
			}
			printf("\n");
			fprintf(battlelog, "\n");
			return 1;
		}
		else if (target == 's' || target == 'S')
		{
			grid[row][column] = '*';
			playerboat->submarine += 1;
			playerstat->total_hits += 1;
			playerstat->total_shots += 1;
			increase(&row, &column);
			if (player == 'm')
			{
				printf("Machine Selects: %d,%d\n", row, column);
			}
			printf("%d,%d is a hit\n", row, column);
			if (player == 'h')
			{
				fprintf(battlelog, "Player 1");
			}
			else
			{
				fprintf(battlelog, "Player 2");
			}
			fprintf(battlelog, ": %d,%d \"hit\"", row, column);
			if (playerboat->submarine == 3)
			{
				printf("The Submarine Has Been Sunk!\n");
				fprintf(battlelog, " Sunk Submarine!");
				playerboat->ships_sunk += 1;
			}
			printf("\n");
			fprintf(battlelog, "\n");
			return 1;
		}
		else if (target == 'd' || target == 'D')
		{
			grid[row][column] = '*';
			playerboat->destroyer += 1;
			playerstat->total_hits += 1;
			playerstat->total_shots += 1;
			increase(&row, &column);
			if (player == 'm')
			{
				printf("Machine Selects: %d,%d\n", row, column);
			}
			printf("%d,%d is a hit\n", row, column);
			if (player == 'h')
			{
				fprintf(battlelog, "Player 1");
			}
			else
			{
				fprintf(battlelog, "Player 2");
			}
			fprintf(battlelog, ": %d,%d \"hit\"", row, column);
			if (playerboat->destroyer == 2)
			{
				printf("The Destroyer Has Been Sunk!\n");
				fprintf(battlelog, " Sunk Destroyer!");
				playerboat->ships_sunk += 1;
			}
			printf("\n");
			fprintf(battlelog, "\n");
			return 1;
		}
		else
		{
			return -1;
		}
	}
}

/*
Function: int is_winner(Boats *player)
Date Created : 3 / 27 / 2017
Date Last Modified : 4 / 02 / 2017
Description : This function is in charge of determining if all ships have been sunk of a player and depending on that if winner or not
Input parameters : Boats *player
Returns : int if winner 1 or not 0
Precondition : Call function
Postconditions : None
*/
int is_winner(Boats *player)
{
	if (player->ships_sunk == 5)
	{
		return 1;
	}
	return 0;
}

/*
Function: void final_stats(Stats *player, Stats *machine, FILE *battlelog)
Date Created : 3 / 27 / 2017
Date Last Modified : 4 / 02 / 2017
Description : This function is in charge of printing all final information to log file
Input parameters : Stats *player, Stats *machine, FILE *battlelog
Returns : None
Precondition : Call function
Postconditions : None
*/
void final_stats(Stats *player, Stats *machine, FILE *battlelog)
{
	double h = 0, m = 0;
	fprintf(battlelog, "*** Player1 Stats ***\n");
	fprintf(battlelog, "Number Hits : %d\n", player->total_hits);
	fprintf(battlelog, "Number Misses : %d\n", player->total_misses);
	fprintf(battlelog, "Total Shots : %d\n", player->total_shots);
	fprintf(battlelog, "Hit / Miss Ratio : %.0lf%%\n\n", player->hits_misses * 100);
	fprintf(battlelog, "*** Player2 Stats ***\n");
	fprintf(battlelog, "Number Hits : %d\n", machine->total_hits);
	fprintf(battlelog, "Number Misses : %d\n", machine->total_misses);
	fprintf(battlelog, "Total Shots : %d\n", machine->total_shots);
	fprintf(battlelog, "Hit / Miss Ratio : %.0lf%%", machine->hits_misses * 100);
}

/*
Function: void hit_miss_ratio(Stats *player, Stats *machine)
Date Created : 3 / 27 / 2017
Date Last Modified : 4 / 02 / 2017
Description : This function is in charge of calculating the ration of hits to misses and inputing it into the stats for the player
Input parameters : Stats *player, Stats *machine
Returns : None
Precondition : Call function
Postconditions : None
*/
void hit_miss_ratio(Stats *player, Stats *machine)
{
	int i = 0;
	double hit = 0, miss = 0;
	hit = player->total_hits;
	miss = player->total_misses;
	player->hits_misses = hit / miss;

	hit = machine->total_hits;
	miss = machine->total_misses;
	machine->hits_misses = hit / miss;
}

/*
Function: void reduce(int *row, int *column)
Date Created : 3 / 27 / 2017
Date Last Modified : 4 / 02 / 2017
Description : This function is in charge of reducing both values by one
Input parameters : int *row, int *column
Returns : None
Precondition : Call function
Postconditions : None
*/
void reduce(int *row, int *column)
{
	*row -= 1;
	*column -= 1;
}

/*
Function: void reduce(int *row, int *column)
Date Created : 3 / 27 / 2017
Date Last Modified : 4 / 02 / 2017
Description : This function is in charge of increasing both values by one
Input parameters : int *row, int *column
Returns : None
Precondition : Call function
Postconditions : None
*/
void increase(int *row, int *column)
{
	*row += 1;
	*column += 1;
}

/*
Function: void clear_screen(void)
Date Created : 3 / 27 / 2017
Date Last Modified : 4 / 02 / 2017
Description : This function is in charge of pausing and the when user preses any button , clearing screen
Input parameters : None
Returns : None
Precondition : Call function
Postconditions : None
*/
void clear_screen(void)
{
	system("pause");
	system("cls");
}

/*
Function: int check_if_fits_grid(int row, int column, char compass, int length, char grid[10][10])
Date Created : 3 / 27 / 2017
Date Last Modified : 4 / 02 / 2017
Description : This function is in charge of checking if the specific ship with that size can be placed within those parameter'
also checks so that their are no overlaps
Input parameters : int row, int column, char compass, int length, char grid[10][10]
Returns : None
Precondition : Call function
Postconditions : None
*/
int check_if_fits_grid(int row, int column, char compass, int length, char grid[10][10])
{
	int x = 0;
	if ((compass == 'D' || compass == 'd') && row <= 10 - length && column >= 0)
	{
		x = 1;
	}
	else if ((compass == 'R' || compass == 'r') && column <= 10 - length && row >= 0)
	{
		x = 1;
	}
	else
	{
		return 0;
	}

	if (check_overlap(row, column, compass, length, grid) == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/*
Function: int check_overlap(int row, int column, char compass, int length, char grid[10][10])
Date Created : 3 / 27 / 2017
Date Last Modified : 4 / 02 / 2017
Description : This function is in charge of checking if their is a ship in the way of the intended placement
returns 1 if there is and 0 if all is ok
Input parameters : int row, int column, char compass, int length, char grid[10][10]
Returns : int 1 if there is something in the way and 0 if all is ok
Precondition : Call function
Postconditions : None
*/
int check_overlap(int row, int column, char compass, int length, char grid[10][10])
{
	int i = 0;
	if (compass == 'D' || compass == 'd')
	{
		for (i = row; i < row + length; i++)
		{
			if (grid[i][column] != '-')
			{
				return 1;
			}
		}
	}
	else if (compass == 'R' || compass == 'r')
	{
		for (i = column; i < column + length; i++)
		{
			if (grid[row][i] != '-')
			{
				return 1;
			}
		}
	}
	return 0;
}

/*
Function: void place_ship(int row, int column, char grid[10][10], char boat, char compass, char player)
Date Created : 3 / 27 / 2017
Date Last Modified : 4 / 02 / 2017
Description : This function is in charge of placing ship
Input parameters : int row, int column, char grid[10][10], char boat, char compass, char player
Returns : None
Precondition : Call function
Postconditions : None
*/
void place_ship(int row, int column, char grid[10][10], char boat, char compass, char player)
{

	int i = 0;
	for (i = 0; i < size(boat); i++)
	{
		grid[row][column] = ship_type(boat, player);
		if (compass == 'd' || compass == 'D')
		{
			row++;
		}
		else if (compass == 'r' || compass == 'R')
		{
			column++;
		}
	}
}

/*
Function: int size(char boat)
Date Created : 3 / 27 / 2017
Date Last Modified : 4 / 02 / 2017
Description : This function is in charge of returning the length of ship depending on its letter
Input parameters : char boat
Returns : int length of boat
Precondition : Call function
Postconditions : None
*/
int size(char boat)
{
	if (boat == 'c')
	{
		return 5;
	}
	else if (boat == 'b')
	{
		return 4;
	}
	else if (boat == 'r')
	{
		return 3;
	}
	else if (boat == 's')
	{
		return 3;
	}
	else
	{
		return 2;
	}
}

/*
Function: char ship_type(char boat, char player)
Date Created : 3 / 27 / 2017
Date Last Modified : 4 / 02 / 2017
Description : This function is in charge of returning charater depending on whos it is
Input parameters : char boat, char player
Returns : character depedning on player and boat
Precondition : Call function
Postconditions : None
*/
char ship_type(char boat, char player)
{
	if (player == 'h')
	{
		if (boat == 'c')
		{
			return 'c';
		}
		else if (boat == 'b')
		{
			return 'b';
		}
		else if (boat == 'r')
		{
			return 'r';
		}
		else if (boat == 's')
		{
			return 's';
		}
		else
		{
			return 'd';
		}
	}
	else
	{
		if (boat == 'c')
		{
			return 'C';
		}
		else if (boat == 'b')
		{
			return 'B';
		}
		else if (boat == 'r')
		{
			return 'R';
		}
		else if (boat == 's')
		{
			return 'S';
		}
		else
		{
			return 'D';
		}
	}
}

/*
Function: void white_on_black(void)
Date Created : 3 / 27 / 2017
Date Last Modified : 4 / 02 / 2017
Description : This function is in charge of changing board color to white on blac
Input parameters : None
Returns : None
Precondition : Call function
Postconditions : None
*/
void white_on_black(void)
{
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 15);
}

/*
Function: void water(void)
Date Created : 3 / 27 / 2017
Date Last Modified : 4 / 02 / 2017
Description : This function is in charge of changing board color to water and white chars
Input parameters : None
Returns : None
Precondition : Call function
Postconditions : None
*/
void water(void)
{
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 23);
}

/*
Function: void miss(void)
Date Created : 3 / 27 / 2017
Date Last Modified : 4 / 02 / 2017
Description : This function is in charge of changing board color to water and a white miss leter
Input parameters : None
Returns : None
Precondition : Call function
Postconditions : None
*/
void miss(void)
{
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 159);
}

/*
Function: void hit(void)
Date Created : 3 / 27 / 2017
Date Last Modified : 4 / 02 / 2017
Description : This function is in charge of changing board color to water and a red hit char
Input parameters : None
Returns : None
Precondition : Call function
Postconditions : None
*/
void hit(void)
{
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 156);
}

/*
Function: void grid_color(char grid[10][10], int row, int column)
Date Created : 3 / 27 / 2017
Date Last Modified : 4 / 02 / 2017
Description : This function is in charge of changing cell color depending on what is in it
Input parameters : char grid[10][10], int row, int column
Returns : None
Precondition : Call function
Postconditions : None
*/
void grid_color(char grid[10][10], int row, int column)
{
	/*if (grid[row][column] == '-' || (grid[row][column] >= 65 && grid[row][column] <= 122 && grid[row][column] != 'm'))
	{
	water();
	}
	else*/ if (grid[row][column] == '*')
	{
		hit();
	}
	else if (grid[row][column] == 'm')
	{
		miss();
	}
	else
	{
		water();
	}
}

/*
Function: void print_type(char grid[10][10], int row, int column)
Date Created : 3 / 27 / 2017
Date Last Modified : 4 / 02 / 2017
Description : This function is in charge of printing characters to screen with spaces depending on what is in that cell
Input parameters : char grid[10][10], int row, int column
Returns : None
Precondition : Call function
Postconditions : None
*/
void print_type(char grid[10][10], int row, int column)
{
	char target = grid[row][column];
	//hit
	if (target == '*')
	{
		printf(" * ");
	}
	//miss
	else if (target == 'm')
	{
		printf(" m ");
	}
	else if (target == 'c')
	{
		printf(" c ");
	}
	else if (target == 'b')
	{
		printf(" b ");
	}
	else if (target == 'r')
	{
		printf(" r ");
	}
	else if (target == 's')
	{
		printf(" s ");
	}
	else if (target == 'd')
	{
		printf(" d ");
	}
	else //if (grid[row][column] == '-' || (grid[row][column] >= 65 && grid[row][column] <= 90))
	{
		printf(" - ");
	}
}

/*
Function: initialize_game_board(char grid[10][10])
Date Created : 3 / 27 / 2017
Date Last Modified : 4 / 02 / 2017
Description : This function is in charge of initializing all of the cells on board to '-'
Input parameters : char grid[10][10]
Returns : None
Precondition : Call function
Postconditions : None
*/
void initialize_game_board(char grid[10][10])
{
	int r = 0, c = 0;

	for (; r < 10; ++r)
	{

		for (c = 0; c < 10; ++c)
		{
			grid[r][c] = '-';
		}
	}
}

/*
Function: void print_grid(char grid[10][10])
Date Created : 3 / 27 / 2017
Date Last Modified : 4 / 02 / 2017
Description : This function is in charge of printing the whole board with numbers on the side
and cells in the color that relates to what is in them
Input parameters : char grid[10][10]
Returns : None
Precondition : Call function
Postconditions : None
*/
void print_grid(char grid[10][10])
{
	//r = rows, c = collums
	int r = 0, c = 0;
	white_on_black();
	printf("   1  2  3  4  5  6  7  8  9 10\n");
	for (; r < 10; ++r)
	{
		white_on_black();
		if (r != 9)
		{
			printf("%d ", r + 1);
		}
		else
		{
			printf("%d", r + 1);
		}
		for (c = 0; c < 10; ++c)
		{
			grid_color(grid, r, c);
			print_type(grid, r, c);
		}
		white_on_black();
		printf("\n");
	}
	printf("\n");
}

/*
Function: void one_play(char grid[10][10], char player, Boats *playerboat, Stats *playerstat, FILE *battlelog)
Date Created : 3 / 27 / 2017
Date Last Modified : 4 / 02 / 2017
Description : This function is in charge of going through one turn, if its for the human it asks them for a target location
and depending what is there, outprints values to screen and log file check check_shot() function on what is outprinted.
For the machine the target is random and check_shot() is also called. If the shot is impossible the process is repeated
Input parameters : char grid[10][10], char player, Boats *playerboat, Stats *playerstat, FILE *battlelog
Returns : None
Precondition : Call function
Postconditions : None
*/
void one_play(char grid[10][10], char player, Boats *playerboat, Stats *playerstat, FILE *battlelog)
{
	int row = 0, column = 0, shot = 0;
	if (player == 'h')
	{
		//asks for coordinates
		printf("Please choose your target location (row column e.g. 2 3): ");
		scanf("%d %d", &row, &column);
		printf("\n");
		//makes value machine redable
		reduce(&row, &column);
		//checks if shot is possible and if it is outprints
		shot = check_shot(grid, row, column, playerboat, playerstat, battlelog, player);
		//while impossible location asks for a new one
		while (shot == -1)
		{
			printf("Invlaid target location, choose another: ");
			scanf("%d %d", &row, &column);
			printf("\n");
			reduce(&row, &column);
			shot = check_shot(grid, row, column, playerboat, playerstat, battlelog, player);
		}

		//randomizer used for tests
		/*do
		{
		random_shot(&row, &column);
		shot = check_shot(grid, row, column, playerboat, playerstat, battlelog, player);
		} while (shot == -1);*/
	}
	else
	{
		//same thing as for human but rnadomized shot
		do
		{
			random_shot(&row, &column);
			shot = check_shot(grid, row, column, playerboat, playerstat, battlelog, player);
		} while (shot == -1);
	}
}

/*
Function: void game_turns(char human[10][10], char machine[10][10], int player, Boats *playerboat, Stats *playerstat, Boats *machineboat, Stats *machinestat, FILE *battlelog)
Date Created : 3 / 27 / 2017
Date Last Modified : 4 / 02 / 2017
Description : This function is in charge of going through the game on a turn by turn basis starting with who was chosen first. The boards are printed every turn.
When game is complete prints who won to screen and and log file and calls function to print statistics into the end of a log file.
Input parameters : char human[10][10], char machine[10][10], int player, Boats *playerboat, Stats *playerstat, Boats *machineboat, Stats *machinestat, FILE *battlelog
Returns : None
Precondition : Call function
Postconditions : None
*/
void game_turns(char human[10][10], char machine[10][10], int player, Boats *playerboat, Stats *playerstat, Boats *machineboat, Stats *machinestat, FILE *battlelog)
{
	int i = player;
	int winner = 0;
	//while ther is no winner keeps game running
	while (winner == 0)
	{
		//clears screen
		clear_screen();
		//player goes first 
		if ((i % 2) == 1)
		{
			printf("Player 1 Board (HUMAN)\n\n");
			print_grid(human);
			printf("Player 2 Board (MACHINE)\n\n");
			print_grid(machine);
			//calls function for one go
			one_play(machine, 'h', machineboat, playerstat, battlelog);
			winner = is_winner(machineboat);
		}
		//machine goes first
		else
		{
			printf("Player 1 Board (HUMAN)\n\n");
			print_grid(human);
			printf("Player 2 Board (MACHINE)\n\n");
			print_grid(machine);
			one_play(human, 'm', playerboat, machinestat, battlelog);
			winner = is_winner(playerboat);
		}
		i++;
	}
	//calculates the hit miss ratio
	hit_miss_ratio(playerstat, machinestat);
	//prints info on who won to screen and log file
	if (is_winner(machineboat) == 1)
	{
		printf("Player1 Wins!\n\n");
		fprintf(battlelog, "Player1 wins, Player2 loses\n\n");
	}
	if (is_winner(playerboat) == 1)
	{
		printf("Player2 Wins!\n\n");
		fprintf(battlelog, "Player1 loses, Player2 wins\n\n");
	}
	//prints final stats to log file
	final_stats(playerstat, machinestat, battlelog);
	//states that the they have been printed to file
	printf("Statistics outputted to logfile successfully!\n");
}

/*
Function: void initialize_stats(Boats *boats, Stats *stats)
Date Created : 3 / 27 / 2017
Date Last Modified : 4 / 02 / 2017
Description : This function is in charge of setting all stats to zero
Input parameters : Boats *boats, Stats *stats
Returns : None
Precondition : Call function
Postconditions : None
*/
void initialize_stats(Boats *boats, Stats *stats)
{
	boats->battleship = 0;
	boats->carrier = 0;
	boats->cruiser = 0;
	boats->destroyer = 0;
	boats->ships_sunk = 0;
	boats->submarine = 0;
	stats->hits_misses = 0;
	stats->total_hits = 0;
	stats->total_misses = 0;
	stats->total_shots = 0;
}

/*
Function: void game(void)
Date Created : 3 / 27 / 2017
Date Last Modified : 4 / 02 / 2017
Description : This is the game function where everything is initialized and different functions for the game to work are called
Input parameters : None
Returns : None
Precondition : Call function
Postconditions : None
*/
void game(void)
{
	//sets the time for later rand operations
	srand((unsigned int)time(NULL));
	//welcomes player and sets a brighter color
	white_on_black();
	welcome_screen();
	white_on_black();
	//initilizes stacs for boats and stats stats
	Stats humanstats;
	Stats machinestats;
	Boats humanboats;
	Boats machineboats;
	//opens file
	FILE *battlelog;
	battlelog = fopen("battleship.log", "w");
	//sets all values in stacks to zero
	initialize_stats(&humanboats, &humanstats);
	initialize_stats(&machineboats, &machinestats);
	//player 1 board created
	char human[10][10] = { 0 };
	//player 2 board created
	char machine[10][10] = { 0 };
	//integer for the randomizer
	int player = 0;
	//replaces all value on both boards to '-'
	initialize_game_board(human);
	initialize_game_board(machine);
	//function for player to choose how he wants to place ships on board
	random_manual(human);
	//randomly places ships on machines bored
	randomly_place_ships_on_board(machine, 'm');
	//randomizer for who goes first
	select_who_starts_first(&player);
	//states thats the machine board has been generated
	printf("Machines board has been generated!\n\n");
	//initilizes game
	game_turns(human, machine, player, &humanboats, &humanstats, &machineboats, &machinestats, battlelog);
	//closes the log file
	fclose(battlelog);
}