#include "Pa6.h"

int main(void)
{
	FILE* outputfile = fopen("battleship.log", "w");

	Dir ship_direction = HORIZ;

	int choice = 0, num  = 0, p1_hits = 0, p1_misses = 0, p2_hits = 0, p2_misses = 0;
	char ship_symbols[5] = { 'c', 'b', 's', 'r', 'd' };
	int row_start = 0, col_start = 0;
	int ship_lengths[5] = { CARRIER_LENGTH, BATTLESHIP_LENGTH, SUBMARINE_LENGTH, CRUISER_LENGTH, DESTROYER_LENGTH};
	int option = 0, shot1 = 0, shot2 = 0, j = 0;
	int num_rows = 0, num_cols = 0;
	char direction = "";

	srand((unsigned)time(NULL));

	char p1_board[MAX_ROWS][MAX_COLS] = { {'~', '~'}, {'~'} };

	char p2_board[MAX_ROWS][MAX_COLS] = { {'~', '~'}, {'~'} };

	char shot_board[MAX_ROWS][MAX_COLS] = { {'~', '~'}, {'~'} };

	welcome_screen();

	system("pause");

	system("cls");

	init_board(p1_board, MAX_ROWS, MAX_COLS);

	init_board(p2_board, MAX_ROWS, MAX_COLS);

	init_board(shot_board, MAX_ROWS, MAX_COLS);

	printf("\nPLayer 1's Board\n");
	
	print_board(p1_board, MAX_ROWS, MAX_COLS);

	printf("\nPLayer 2's Board\n");

	print_board(p2_board, MAX_ROWS, MAX_COLS);

	printf("\n1. Enter your psositions of ships manually\n");

	printf("\n2.Allow the program to randomly select positions of ships.\n");

	scanf("%d", &choice);

	if (choice == 1)
	{
		for (int i = 0; i < 5; i++)
		{
			manually_place_ships_on_board(p1_board, ship_lengths, ship_symbols, j);
			j++;
		}
		

	}

	if (choice == 2)
	{
		ship_direction = gen_direction();

		generateStartingPoint(p1_board,num_rows, num_cols, ship_lengths, ship_symbols, row_start, col_start, ship_direction, j);

		/*print_board(p1_board, MAX_ROWS, MAX_COLS);*/

	}
	generateStartingPoint(p2_board, num_rows, num_cols, ship_lengths, ship_symbols, row_start, col_start, ship_direction, j);
	print_board(shot_board, MAX_ROWS, MAX_COLS);
	print_board(p1_board, MAX_ROWS, MAX_COLS);
	system("pause");
	option = rand() % 2;
	int game = 0;
	while (sunk_ship(p1_board, num_rows, num_cols, ship_lengths, ship_symbols, ship_direction,
		row_start, col_start) != 5 && sunk_ship(p2_board, num_rows, num_cols, ship_lengths, ship_symbols, ship_direction,
			row_start, col_start) != 5)
	{
		if (option == 0)
		{
			system("cls");
			

			print_board(p1_board, MAX_ROWS, MAX_COLS);

			print_board(shot_board, MAX_ROWS, MAX_COLS);

			p2_shoot(outputfile, p1_board, p2_hits, p2_misses);
			system("cls");
			system("pause");
			print_board(p1_board, MAX_ROWS, MAX_COLS);
			
			print_board(shot_board, MAX_ROWS, MAX_COLS);
			p1_shot(outputfile, p2_board, shot_board, p1_hits, p1_misses);

			print_board(shot_board, MAX_ROWS, MAX_COLS);

			system("cls");
			print_board(p1_board, MAX_ROWS, MAX_COLS);
			print_board(shot_board, MAX_ROWS, MAX_COLS);

		}
		else
		{
			system("cls");
			
			print_board(p1_board, MAX_ROWS, MAX_COLS);

			print_board(shot_board, MAX_ROWS, MAX_COLS);

			p1_shot(outputfile, p2_board, shot_board, p1_hits, p1_misses);
			
			system("cls");
			system("pause");

			print_board(p1_board, MAX_ROWS, MAX_COLS);

			print_board(shot_board, MAX_ROWS, MAX_COLS);
			
			p2_shoot(outputfile, p1_board, p2_hits, p2_misses);
			print_board(shot_board, MAX_ROWS, MAX_COLS);

			system("cls");
			print_board(p1_board, MAX_ROWS, MAX_COLS);
			print_board(shot_board, MAX_ROWS, MAX_COLS);
		}
	}
	
	if (sunk_ship(p1_board, num_rows, num_cols, ship_lengths, ship_symbols, ship_direction,
		row_start, col_start) == 5)
	{
		game = 1;
	}
	else
	{
		game = 2;
	}
	
	if (game == 1)
	{
		printf("\nPLAYER 1 WINS!!");
	}
	else
	{
		printf("\nPLAYER 2 WINS!!");
	}
	

	fprintf(outputfile, "\nP1 hits: %d\n", p1_hits);
	fprintf(outputfile, "\nP1 misses: %d\n", p1_misses);
	fprintf(outputfile, "\nP1 hit miss percetange: %d\n", p1_hits / p1_misses);
	if (game == 1)
	{
		fprintf(outputfile, "\nP1 WON\n");
	}
	else
	{
		fprintf(outputfile, "\nP1 LOSS\n");
	}
	fprintf(outputfile, "\nP2 hits: %d\n", p2_hits);
	fprintf(outputfile, "\nP2 misses: %d\n", p2_misses);
	fprintf(outputfile, "\nP2 hit miss percetange: %d\n", p2_hits / p2_misses);
	if (game == 2)
	{
		fprintf(outputfile, "\nP2 WON\n");
	}
	else
	{
		fprintf(outputfile, "\nP2 LOSS\n");
	}
	fclose(outputfile);

	return 0;
}
