#include "main.h"

/**
 * flip_bits - returns the required amount of bits
 * required to flip to go from one number 
 * the other
 * @n: first number.
 * @m: second number.
 *
 * Return: number of bits.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int bitsNumber;

	for (bitsNumber = 0; n || m; n >>= 1, m >>= 1)
	{
		if ((n & 1) != (m & 1))
		{
			bitsNumber++;
		}
	}

	return (bitsNumber);
}
