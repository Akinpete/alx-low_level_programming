#include "main.h"

/**
 * print_sign - prints +, 0, - when n is
 * greater than, less than, or equals 0
 *
 * @n: The character in ASCII code
 *
 * Return: 0 for zero, 1 for positive, -1 for the rest.
 */
int print_sign(int n)
{
	if (n > 0)
	{
		_putchar(43);
		return (1);
	}
	else if (n == 0)
	{
		_putchar(48);
		return (0);
	}
	else
	{
		_putchar(45);
		return (-1);
	}
	_putchar('\n');
}
