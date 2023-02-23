#include "main.h"

/**
 * print_alphabet_x10 - program printing lowercase alphabetx10
 *
 * Reurn: Always (0) Success
 */
void print_alphabet_x10(void)
{
	int t = 0, i;

	while (t < 10)
	{
		for (i = 97; i <= 122; i++)
		{
			_putchar(i);
		}
	_putchar('\n');
	t++;
	}
}
