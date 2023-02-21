#include <stdio.h>

/**
 * main - prints letter q and e.
 *
 * Return: Always (0) Success
 */
int main(void)
{
	int a = 97, z = 122;

	while (a <= z)
	{
		if (a != 101 && a != 113)
			putchar(a);
		a++;
	}
	putchar('\n');
	return (0);
}
