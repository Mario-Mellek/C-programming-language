#include <stdio.h>

int main(void)
{
	int play()
	{	
		printf("\nRock\tPaper\tScissors");
		printf("\n1\t2\t3");
		int input;
		do
		{
			printf("\n\nSelect a number: ");
			scanf("%d", &input);
		}while((input > 3) || (input <= 0));
		switch(input)
		{
			case 1:
				printf("\nYou selected Rock, %d\n", input);
				break;
			case 2:
				printf("\nYou selected Paper, %d\n", input);
				break;
			case 3:
				printf("\nYou selected Scissors, %d\n", input);
				break;
			default:
				printf("\nCould detect a selection\n");
		}
		printf("-- Computer Selection --");
	}
	int i;
	for (i = 1; i <= 5; i++)
	{
		printf("\n\n------------Round number %d------------", i);
		play();
	}
	return (0);
}
