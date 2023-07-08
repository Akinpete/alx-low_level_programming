#include "main.h"
#include <stdio.h>

/**
 * set_bit - sets the value of a bit to 1.
 * at a given index.
 * @n: pointer of an unsigned long int.
 * @index: index of the bit.
 *
 * Return: returns 1 if it runs, -1 if i.
 * here's an issue.
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned int u_i;

	if (index > 63)
	{
		return (-1);
	}

	u_i = 1 << index;
	*n = (*n | u_i);

	return (1);
}
