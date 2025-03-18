#include <stdio.h>
int win(char *grid);

int main()
{

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