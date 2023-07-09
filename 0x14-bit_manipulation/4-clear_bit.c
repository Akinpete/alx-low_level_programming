#include "main.h"
#include <stdio.h>

/**
 * clear_bit - sets the value of a bit to 0.
 * 
 * @n: points to unsigned integer.
 * @index: index of the bit in question.
 *
 * Return: 1 if the code runs.
 * -1 when it doesn't.
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned int u_i;

	if (index > 63)
		return (-1);

	u_i = 1 << index;

	if (*n & u_i)
		*n ^= u_i;

	return (1);
}
