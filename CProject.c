#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 9

int win(char *grid, char inp);

int main()
{
	int j; //Turns
	int i; //i=row
	int w = 0, l = 0, t = 0; //Number of wins, loses or ties
	int ng = 0; //Stays 0 to play a new game and changes to 1 if the user wants to stop playing
	int	n = 0; //Checks if the spaces are free each turn
	char userToken, botToken, opt, playAgain=0, turnInp;
	srand(time(NULL));

	printf("Please select your token X or O: ");	//here we prompt the user for the token he wants to use
	scanf_s(" %c" +1, &opt);
	if (opt == 'X'|| opt=='x')
	{
		userToken = 'X';
		botToken = 'O';
	}
	else
	{
		userToken = 'O';
		botToken = 'X';
	}
	while (ng < 1)	//This loop enables the play again function and only breaks when player stops playing
	{
		char arr[SIZE] = { '0','1','2',	//Here I reset the game
						'3','4','5',
						'6','7','8' };

		for (i = 0; i < SIZE; i++) //This loop displays the grid
		{
			printf("%c |", arr[i]);
			if (i == 2)
			{
				printf("\n");
				printf("---------");
				printf("\n");
			}
			if (i == 5)
			{
				printf("\n");
				printf("---------");
				printf("\n");
			}
			if (i == 8)
			{
				printf("\n\n");
			}
		}

		for (j = 0; j < 9; j++)
		{
			if (j % 2 == 0) //Insert player turn here
			{
				n = 0;
				while (n < 1)
				{
					printf("Please select a free space: ");
					scanf_s(" %c", &turnInp);
					if (turnInp == arr[turnInp - 48])
					{
						arr[turnInp - 48] = userToken;
						n++;
					}
					else
					{
						printf("Please insert a free space: ");
					}
				}
			}

			else //Insert computer turn here
			{
				n = 0;
				while (n < 1)
				{
					char turnInp = (rand() % 9 )+ 48;

					if (turnInp == arr[turnInp - 48])
					{
						arr[turnInp - 48] = botToken;
						n++;
					}
				}
			}

			for (i = 0; i < SIZE; i++) //This loop displays the grid
			{
				printf("%c |", arr[i]);
				if (i == 2)
				{
					printf("\n");
					printf("---------");
					printf("\n");
				}
				if (i == 5)
				{
					printf("\n");
					printf("---------");
					printf("\n");
				}
				if (i == 8)
				{
					printf("\n\n");
				}
			}

			if (win(&arr[0], userToken) == 1) //The function win returns 1 if player won
			{
				printf("You win\n");
				j = 10;			//Here I set j to 10 to exit the loop but not set it to the inmediate after the loop to make a tie option
				w++;
			}

			else if (win(&arr[0], userToken) == 2) //And 2 if the player lost
			{
				printf("You lose\n");
				j = 10;
				l++;
			}
		}

		if (j == 9)	 //If the loop finished naturally it means it is a tie
		{
			printf("It's a tie!!\n");
			t++;
		}

		printf("Wins: %i, Loses: %i, Ties: %i \n Would you like to play again? Y/N\n", w, l, t);
		scanf_s(" %c", &playAgain);
		switch (playAgain)
		{
		case 'N':
			printf("Goodbye, thanks for playing");
			ng++;
			break;
		case 'n':
			printf("Goodbye, thanks for playing");
			ng++;
			break;
		case 'Y':
			break;
		case 'y':
			break;
		default:
			printf("Not a valid character");
		}
	}
	
	return 0;
}

int win(char* grid, char inp)
{
	int winner = 0;
	int i;

	for (i = 0; i < 3; i++)
	{
		if (*(grid + i) == *(grid + i + 3) && *(grid + i) == *(grid + i + 6))
		{
			if (*(grid + i) == inp)
			{
				winner = 1;
			}
			else
			{
				winner = 2;
			}
		}
	}
	for (i = 0; i <= 6; i+=3)
	{
		if (*(grid + i) == *(grid + i + 1) && *(grid + i) == *(grid + i + 2))
		{
			if (*(grid + i) == inp)
			{
				winner = 1;
			}
			else
			{
				winner = 2;
			}
		}
	}
	if (*grid == *(grid + 4) && *grid == *(grid + 8))
	{
		if (*grid  == inp)
		{
			winner = 1;
		}
		else
		{
			winner = 2;
		}
	}
	if (*(grid+2) == *(grid + 4) && *(grid+2) == *(grid + 6))
	{
		if (*(grid + 2) == inp)
		{
			winner = 1;
		}
		else
		{
			winner = 2;
		}
	}
	return winner;
}