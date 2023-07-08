#include "main.h"
#include <stdio.h>

/**
 * binary_to_uint - converts binary numbers to
 * unsigned int.
 * @b: binary.
 *
 * Return: unsigned int.
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int u_i;

	int length, bin;

	if (!b)
		return (0);

	u_i = 0;

	for (length = 0; b[length] != '\0'; length++)
		;

	for (length--, bin = 1; length >= 0; length--, bin *= 2)
	{
		if (b[length] != '0' && b[length] != '1')
		{
			return (0);
		}

		if (b[length] & 1)
		{
			u_i += bin;
		}
	}

	return (u_i);
}
