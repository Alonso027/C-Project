//18/3/25

#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 9


int main()
{
	char arr[SIZE];
	int i; //i=row j=colum
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