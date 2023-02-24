#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
int play(void);
int player = 0;
int computer = 0;
char name[20];

#define randnum(min, max) \
	((rand() % (int)(((max) + 1) - (min))) + (min))

int main(void)
{
	int i;

	do {
	printf("\n\nEnter your name: ");
	scanf("%19s", name);
	if (isalpha(name[0]) == 0)
		printf("Your name must start with a charachter");
	} while (isalpha(name[0]) == 0);

	for (i = 1; i <= 3; i++)
	{
		printf("\n\n------------Round number %d------------", i);
		play();
		printf("%s: %d\nComputer: %d", name, player, computer);
		putchar('\n');
	}
	if (computer > player)
	{
		printf("----------You Lost----------\n");
	} else if (player > computer)
	{
		printf("----------You Won----------\n");

	} else
	{
		printf("----------It's a tie----------\n");
	}
	printf("\n\n\t__GAME OVER__\n\n");
	return (0);
}

int play(void)
{
	printf("\nRock\tPaper\tScissors");
	printf("\n1\t2\t3");
	int input;

	do {
		printf("\n\nSelect a number: ");
		scanf("%d", &input);
	} while ((input > 3) || (input <= 0));

	switch (input)
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
	printf("\n\n-- Computer Selection --\n");
	srand(time(NULL));
	switch (randnum(1, 3))
	{
		case 1:
			printf("\nComputer Played Rock\n");
			input == 3 ? (printf("You lost this round") &&
					(computer += 1))
				: input == 2 ? (printf("You won this round") &&
						(player += 1))
				: printf("It's a tie");
				putchar('\n');
			break;
		case 2:
			printf("\nComputer played Paper\n");
			input == 1 ? (printf("You lost this round") &&
					(computer += 1))
				: input == 3 ? (printf("You won this round") &&
						(player += 1))

				: printf("It's a tie");
				putchar('\n');
			break;
		case 3:
			printf("\nComputer played Scissors\n");
			input == 2 ? (printf("You lost this round") &&
					(computer += 1))
				: input == 1 ? (printf("You won this round") &&
						(player += 1))
				: printf("It's a tie");
				putchar('\n');
			break;
		default:
			printf("Computer couldn't play");
	}
}
