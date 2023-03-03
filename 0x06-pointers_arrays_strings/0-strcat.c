#include "main.h"
#include <stdio.h>

/**
 * _strcat -concatenates two strings
 * @dest: points to the destination string
 * @src: points to the source string
 *
 * Return: Points to the resulting string destination
 */


char *_strcat(char *dest, char *src)
{
	int length_d = 0;
	int i;

	while (dest[length_d])
	{
		length_d++;
	}

	for (i =0; src[i] != 0; i++)
	{
		dest[length_d] = src[i];
			length_d++;
	}

	dest[length_d] = '\0';
	return (dest);
}
