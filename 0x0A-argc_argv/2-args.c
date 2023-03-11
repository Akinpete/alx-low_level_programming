#include <stdio.h>

/**
 * main - prints the arguments passed into it
 * @argc: number of arguments passed into program
 * @argv: array of passed arguments
 * Return: always 0 (success)
 */

int main(int argc, char **argv)
{
	int i;

	for (i = 0; i < argc; i++)
	{
		printf("%s\n", argv[i]);
	}
	return (0);
}
