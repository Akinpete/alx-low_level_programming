#include <stdio.h>
#include "main.h"

/**
 * clear_bit - sets the value of a bit to 0.
  * @n: points to unsigned integer.
 * @index: index of the bit in question.
  * Return: 1 if the code runs.
 * -1 when it doesn't.
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
	{
		return (-1);
	}

	*n &= ~(1UL << index);
	return (1);

}

