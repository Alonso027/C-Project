#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 9

int win(char *grid, char inp);

int main()
{
	char arr[SIZE] =  { '0','1','2',
						'3','4','5',
						'6','7','8' };
	int j; //Turns
	int i; //i=row
	int w=0, l=0, t=0, ng=0;
	char userToken, opt, playAgain;

	printf("Please select your token X or O: ");	//here we prompt the user for the token he wants to use
	scanf_s(" %c" +1, &opt);
	if (opt == 'X'|| opt=='x')
	{
		userToken = 'X';
	}
	else
	{
		userToken = 'O';
	}
	while (ng != 1)	//This loop enables the play again function and only breaks when player stops playing
	{
		for (j = 0; j <= 9; j++)
		{
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
			}

			if (j % 2 == 0) //Insert player turn here
			{

			}

			else //Insert computer turn here
			{

			}

			if (win(&arr[0], userToken) == 1) //The function win returns 1 if player won
			{
				printf("You win");
				j = 10;			//Here I set j to 10 to exit the loop but not set it to the inmediate after the loop to make a tie option
				w++;
			}

			else if (win(&arr[0], userToken) == 2) //And 2 if the player lost
			{
				printf("You lose");
				j = 10;
				l++;
			}
		}

		if (j = 9)	 //If the loop finished naturally it means it is a tie
		{
			printf("It's a tie!!");
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
			printf("Please enter a valid character");
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
	for (i = 0; i < 6; i+=3)
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