#include "main.h"
#include <stdio.h>

/**
* _strcat - Concatenates two strings
* @dest: The destination string
* @src: The source string
* Return: Apointer to the resulting string dest
*/

char *_strcat(char *dest, char *src)
{

	int lendest = 0, i;

	while (dest[lendest])
	{
		lendest++;
	}

	for (i = 0; src[i] != 0; i++)
	{
		dest[lendest] = src[i];
		lendest++;
	}

	dest[lendest] = '\0';
	return (dest);
}
