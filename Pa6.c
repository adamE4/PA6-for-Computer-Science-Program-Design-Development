#include "Pa6.h"

/*
	* Programmer: Adam El-Mobdy
	* Course: Compuer Science 121
	* Lab Section: 4
	* Assigement: Programming Assigment 6
	* Description: This the welcomne screen to the game

*/
void welcome_screen()
{
	printf("***** Welcome to Battleship *****\n");
	printf("\n1. This is a 2 player game.");
	printf("\n2. PLayer1 is you and Player 2 is the cpu.");
	printf("\n3. The objact of the game to sink the other players ships, the first to do so wins!");
	printf("\n4. Each player will alternate turns, GOOD LUCK ;)");
}
/*
	* Programmer: Adam El-Mobdy
	* Course: Compuer Science 121
	* Lab Section: 4
	* Assigement: Programming Assigment 6
	* Description: This function is initializing the game baord 

*/
void init_board(char board[][MAX_COLS], int num_rows, int num_cols)
{
	int row_index = 0, col_index = 0;

	for (; row_index < num_rows; ++row_index)
	{
		for (col_index = 0; col_index < num_cols; ++col_index) 
		{
			board[row_index][col_index] = '~';
		}
	}
}
/*
	* Programmer: Adam El-Mobdy
	* Course: Compuer Science 121
	* Lab Section: 4
	* Assigement: Programming Assigment 6
	* Description: This functiomn prints the game board

*/
void print_board(char board[][MAX_COLS], int num_rows, int num_cols)
{
	int row_index = 0, col_index = 0;

	printf("%3d%2d%2d%2d%2d%2d%2d%2d%2d%2d\n",
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9);

	for (; row_index < num_rows; ++row_index) 
	{
		printf("%-2d", row_index);
		for (col_index = 0; col_index < num_cols; ++col_index)
		{
			printf("%-2c", board[row_index][col_index]);
		}

		putchar('\n');
	}

}
/*
	* Programmer: Adam El-Mobdy
	* Course: Compuer Science 121
	* Lab Section: 4
	* Assigement: Programming Assigment 6
	* Description: This function decides who starts the game

*/
int who_starts(int num)
{
	int start = rand() % 2 + 1;
	return start;
}
/*
	* Programmer: Adam El-Mobdy
	* Course: Compuer Science 121
	* Lab Section: 4
	* Assigement: Programming Assigment 6
	* Description: This function return the int j

*/
int function()
{
	int j = 0;
	return j;
}
/*
	* Programmer: Adam El-Mobdy
	* Course: Compuer Science 121
	* Lab Section: 4
	* Assigement: Programming Assigment 6
	* Description: This function makes it so the user can place the ships on the board

*/
int manually_place_ships_on_board(char p1_board[][MAX_COLS], int ship_lengths[5], char ship_symbols[5], int j)
{
	int first = 0, second = 0; 
	int direction = 0;
	
	printf("What direction would like to place your ship [Horz[1]/Vert[2]: ");
	scanf("%d", &direction);
	
	if (direction == 1)
	{
		printf("Please enter where you would your ship to start: ");
		scanf("%d%d", &first, &second);
		for (int i = 0; i < ship_lengths[j] + 1; i++)
		{
			if (p1_board[first][second] == '/0')
			{
				printf("Please re-enter where you would your ship to start: ");
				scanf("%d%d", &first, &second);
			}

			p1_board[first][second] = ship_symbols[j];
			second++;

		}
	}
		
		
	if (direction == 2)
	{
		printf("Please enter where you would your ship to start: ");
		scanf("%d%d", &first, &second);
		for (int i = 0; i < ship_lengths[j] + 1; i++)
		{
			if (p1_board[first][second] == '/0')
			{
				printf("Please re-enter where you would your ship to start: ");
				scanf("%d%d", &first, &second);
			}

			p1_board[first][second] = ship_symbols[j];
			first++;



		}
	}
	print_board(p1_board, MAX_ROWS, MAX_COLS);
}
/*
	* Programmer: Adam El-Mobdy
	* Course: Compuer Science 121
	* Lab Section: 4
	* Assigement: Programming Assigment 6
	* Description: This function decides the direction at random

*/
Dir gen_direction(void)
{
return ((Dir)(rand() % 2));
}


/*
	* Programmer: Adam El-Mobdy
	* Course: Compuer Science 121
	* Lab Section: 4
	* Assigement: Programming Assigment 6
	* Description: This function places the ships at random 

*/
int generateStartingPoint(char board[][MAX_COLS], int num_rows, int num_cols, int ship_lengths[5], char ship_symbols[5],
	Dir direction, int row_start, int col_start, int j)
{
	int count = 0;
	for (int i = 0; i < 5; i++)
	{
		direction = gen_direction();
	
		if (direction == HORIZ)
		{
			row_start = rand() % (MAX_ROWS);
			col_start = rand() % (MAX_COLS - ship_lengths[i] - 1);

			for (int check = 0; check < ship_lengths[count]; check++)
			{
				if (board[row_start][col_start + check] != '~')
				{
					check = 0;
					direction = gen_direction();
					row_start = rand() % (MAX_ROWS);
					col_start = rand() % (MAX_COLS - ship_lengths[i] - 1);
				}
				if (check == ship_lengths[count])
				{
					for (int y = 0; y < ship_lengths[count]; y++)
					{
						if (board[row_start][col_start + check] == '~')
						{
							count++;

						}
					}
				}
				
				
				
				
				
			}
			
			
			
				for (int x = 0; x < ship_lengths[i]; x++)
				{
					

					if (board[row_start][col_start] != 'c' || board[row_start][col_start] != 'b' || board[row_start][col_start] != 's' || 
						board[row_start][col_start] != 'b' || board[row_start][col_start] != 'r' || board[row_start][col_start] != 'd')
					{
						board[row_start][col_start + x] = ship_symbols[j];
					}
					else if (board[row_start][col_start] == 'c' || board[row_start][col_start] == 'b' || board[row_start][col_start] == 's' ||
						board[row_start][col_start] == 'b' || board[row_start][col_start] == 'r' || board[row_start][col_start] == 'd')
					{
						row_start = rand() % (MAX_ROWS);
						col_start = rand() % (MAX_COLS - ship_lengths[i] - 1);
					}

				}
		}

		else if (direction == VERT)
		{
			

			col_start = rand() % (MAX_COLS);
			row_start = rand() % (MAX_ROWS - ship_lengths[i] - 1);
			for (int check = 0; check < ship_lengths[count]; check++)
			{
				if (board[row_start + check][col_start] != '~' )
				{
					check = 0;
					direction = gen_direction();
					row_start = rand() % (MAX_ROWS);
					col_start = rand() % (MAX_COLS - ship_lengths[i] - 1);
				}
				if (check == ship_lengths[count] - 1)
				{
					for (int y = 0; y < ship_lengths[count]; y++)
					{
						if (board[row_start + check][col_start] == '~')
						{
							count++;

						}
					}
				}
				
				
				
				
				
			}
			

			for (int x = 0; x < ship_lengths[i]; x++)
			{
			
				if (board[row_start][col_start] != 'c' || board[row_start][col_start] != 'b' || board[row_start][col_start] != 's' ||
					board[row_start][col_start] != 'b' || board[row_start][col_start] != 'r' || board[row_start][col_start] != 'd')
				{
					board[row_start + x][col_start] = ship_symbols[j];
				}
				else if (board[row_start][col_start] == 'c' || board[row_start][col_start] == 'b' || board[row_start][col_start] == 's' ||
					board[row_start][col_start] == 'b' || board[row_start][col_start] == 'r' || board[row_start][col_start] == 'd')
				{
					row_start = rand() % (MAX_ROWS);
					col_start = rand() % (MAX_COLS - ship_lengths[i] - 1);
				}
				
			
				
			}
		}
		j++;
		row_start = 0;
		col_start = 0;
	}

}

/*
	* Programmer: Adam El-Mobdy
	* Course: Compuer Science 121
	* Lab Section: 4
	* Assigement: Programming Assigment 6
	* Description: This function makes the computer shoot at random

*/
int p2_shoot(FILE* outputfile, char p1_board[][MAX_COLS], int* p2_hits, int* p2_misses)
{
	int p2_shot1 = 0, p2_shot2 = 0;
	p2_shot1 = rand() % (10);
	p2_shot2 = rand() % (10);
	if (p1_board[p2_shot1][p2_shot2] == '*' || p1_board[p2_shot1][p2_shot2] == 'm')
	{
		p2_shot1 = rand() % (10);
		p2_shot2 = rand() % (10);
	}
	if (p1_board[p2_shot1][p2_shot2] == 'c' || p1_board[p2_shot1][p2_shot2] == 'b' || p1_board[p2_shot1][p2_shot2] == 's' || p1_board[p2_shot1][p2_shot2] == 'r' ||
		p1_board[p2_shot1][p2_shot2] == 'd')
	{
		p1_board[p2_shot1][p2_shot2] = '*';
		printf("\nThe Comuter has hit Your Ship!! at %d %d\n", p2_shot1, p2_shot2);
		fprintf(outputfile, "\nThe Computer has hit your ship at %d %d\n", p2_shot1,p2_shot2);
		*p2_hits++;
	}
	else
	{
		p1_board[p2_shot1][p2_shot2] = 'm';
		*p2_misses++;
	}
	
}

/*
	* Programmer: Adam El-Mobdy
	* Course: Compuer Science 121
	* Lab Section: 4
	* Assigement: Programming Assigment 6
	* Description: This function makes it so the user can shoot 

*/
int p1_shot(FILE* outputfile, char p2_board[][MAX_COLS],char shot_board[][MAX_COLS], int* p1_hits, int* p1_misses)
{
	int first = 0, second = 0;
	printf("PLease enter where you would like to shoot: ");
	scanf("%d%d", &first, &second);

	if (first > 9 || second > 9)
	{
		printf("PLease re-enter where you would like to shoot: ");
		scanf("%d%d", &first, &second);
	}
	if (p2_board[first][second] == '*' || p2_board[first][second] == 'm')
	{
		printf("PLease re-enter where you would like to shoot: ");
		scanf("%d%d", &first, &second);
	}
	if (p2_board[first][second] == 'c' || p2_board[first][second] == 'b' || p2_board[first][second] == 's' || p2_board[first][second] == 'r' ||
		p2_board[first][second] == 'd')
	{
		p2_board[first][second] = '*';
		shot_board[first][second] = '*';
		fprintf(outputfile, "\n%d %d was a hit!!\n", first, second);
		*p1_hits++;
	}
	else
	{
		p2_board[first][second] = 'm';
		shot_board[first][second] = 'm';
		printf("\n%d %d was a miss:(\n", first, second);
		fprintf(outputfile,"\n%d %d was a miss:(\n", first, second);
		p1_misses++;
	}
}

/*
	* Programmer: Adam El-Mobdy
	* Course: Compuer Science 121
	* Lab Section: 4
	* Assigement: Programming Assigment 6
	* Description: This function counts the number of ship sunk

*/
int sunk_ship(char board[][MAX_COLS], int num_rows, int num_cols, int ship_lengths[5], char ship_symbols[5], Dir direction,
	int row_start, int col_start)
{
	int i = 0, j = 0, counter = 0, ship_sunk = 0, placer = 0, c = 0, b = 0, s = 0, r = 0, d = 0;
	
	for (; i < 10; i++)
	{
		for (; j < 10; j++)
		{
			if (board[i][j] == 'c')
			{
				c++;
			}
			else if (board[i][j] == 'b')
			{
				b++;
			}
			else if (board[i][j] == 's')
			{
				s++;
			}
			else if (board[i][j] == 'r')
			{
				r++;
			}
			else if (board[i][j] == 'd')
			{
				d++;
			}
			if (c == 0)
			{
				ship_sunk++;
			}
			if (b == 0)
			{
				ship_sunk++;
			}
			if (s == 0)
			{
				ship_sunk++;
			}
			if (r == 0)
			{
				ship_sunk++;
			}
			if (r == 0)
			{
				ship_sunk++;
			}
			if (d == 0)
			{
				ship_sunk++;
			}


		}
	}

	return ship_sunk;
}
