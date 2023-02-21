#include <stdio.h>

/**
 * main - prints lowercase before uppercase alphabets.
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
	a = 65, z = 90;
	do {
		putchar(a);
		a++;
	} while (a <= z);
	putchar('\n');
	return (0);
}
