#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 9

int win(char *grid);

int main()
{
	char arr[SIZE];
	int i; //i=row
	char userToken;
	char X, O, opt;

	printf("Please select your token X or O: ");
	scanf_s(" %c" +1, &opt);

	if (opt == 'X'|| opt=='x')
	{
		userToken = 'X';
	}
	else
	{
		userToken = 'O';
	}

	for (i = 0; i < SIZE; i++)
	{
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

		printf("%c |", arr[i]);
	}






	return 0;
}

int win(char* grid)
{
	int winner = 0;
	int i;
	for (i = 0; i < 3; i++)
	{
		if (*(grid + i) == *(grid + i + 3) && *(grid + i) == *(grid + i + 6))
		{
			winner = 1;
		}
	}
	for (i = 0; i < 6; i+=3)
	{
		if (*(grid + i) == *(grid + i + 1) && *(grid + i) == *(grid + i + 2))
		{
			winner = 1;
		}
	}
	if (*grid == *(grid + 4) && *grid == *(grid + 8))
	{
		winner = 1;
	}
	if (*(grid+2) == *(grid + 4) && *(grid+2) == *(grid + 6))
	{
		winner = 1;
	}
	return winner;
}