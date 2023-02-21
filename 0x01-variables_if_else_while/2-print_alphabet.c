#include <stdio.h>

/**
 * main - prints lowercase alphabet.
 *
 * Return: Always (0) Success
 */
int main(void)
{
	int a = 97, z = 122;

	do {
		putchar(a);
		a++;
	} while (a <= z);
	putchar('\n');
	return (0);
}
