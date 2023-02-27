#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
void play(void);
int player = 0;
int computer = 0;
char name[10];

#define randnum(min, max) \
	((rand() % (int)(((max) + 1) - (min))) + (min))

/**
  * main - (Entry point) asks for the user's name and
  * loops over the play function 3 times for 3 rounds
  * Return: returns 0
  */


int main(void)
{
	int i;

	printf("Rock Paper Scissors");

	// prompt asking for the name(Must start with a charachter)
	do {
	printf("\n\nEnter your name: ");
	scanf("%9s", name);
	if (isalpha(name[0]) == 0)
		printf("Your name must start with a charachter");
	} while (isalpha(name[0]) == 0);

	//calling the function 3 times for 3 rounds
	for (i = 1; i <= 3; i++)
	{
		printf("\n\n------------------Round number %d------------------", i);
		play();
		printf("+=====================+====================+\n");
		printf("|         %s       |       Computer     |\n", name);
		printf("+=====================+====================+\n");
		printf("|           %d         |          %d         |\n", player, computer);
		printf("+=====================+====================+\n");
		putchar('\n');
	}

	// Printing final score(Game-Over)
	if (computer > player)
	{
		printf("-------------You Lost-------------\n");
	} else if (player > computer)
	{
		printf("-------------You Won-------------\n");

	} else
	{
		printf("-------------It's a tie-------------\n");
	}
	printf("\n\n\t__GAME OVER__\n");
	printf("%s: %d\tComputer: %d\n\n", name, player, computer);
	return (0);
}

/**
  * play - A function that starts 1 round, it asks for the player's input
  * and saves the round's score
  */

void play(void)
{
	// start round
	printf("\n\tRock\t|\tPaper\t|     Scissors   |");
	printf("\n--------------------------------------------------");
	printf(" \n\t1\t|\t2\t|\t3\t |");
	printf("\n--------------------------------------------------");
	int input;

	//selecting an input(must be from 0 to 3)
	do {
		printf("\n\nSelect a number: ");
		scanf("%d", &input);
	} while ((input > 3) || (input <= 0));

	//switch statment that prints user's selection
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
	/*
	 * initializing the seed of random to get random
	 * numbers each time the code runs
	 */
	srand(time(NULL));


	/*
	 * switch statment that displays the result and saves
	 * the score of the round to their designated variables
	 *
	 * each case has a conditional statment
	 * to increment the winner's score
	 */
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
