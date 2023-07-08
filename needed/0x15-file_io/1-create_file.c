#include <stdio.h>
#include <sys/stat.h>
#include <stdio.h>
#include <sys/types.h>
#include "main.h"
#include <string.h>

/**
 * create_file - creates a file
 * @filename: name of file to be created
 * @text_context: text to be written to file
 *
 * Return: 1 or -1
 */
int create_file(const char *filename, char *text_context)
{
	FILE *fp; /* pointer to a FILE object */
	mode_t mode; /* sets permissions to a file */
	int write_check;
	int chmod_check;

	if (access(filename, F_OK) == 0) /* if file exists) */
	{
		fp = fopen(filename, "w"); /* open file in write mode, overwrite */

		if (fp == NULL || filename == NULL)
			return (-1);
		if (text_context != NULL)
			write_check = fwrite(text_context, sizeof(char), strlen(text_context), fp);
		if (write_check == -1) /* write unsuccessful */
			return (-1);
		fclose(fp); /* close file */
		return (1);
	}
	else /* File doesn't exists */
	{
		fp = fopen(filename, "w"); /* open file in write mode */
		if (fp == NULL || filename == NULL)
			return (-1);
		if (text_context != NULL)
			write_check = fwrite(text_context, sizeof(char), strlen(text_context), fp);
		if (write_check == -1) /* write unsuccessful */
			return (-1);
		fclose(fp); /* close file */

		mode = S_IRUSR | S_IWUSR; /* specify permissions */
		chmod_check = chmod(filename, mode);

		if (chmod_check != 0) /* permission change failed */
			return (0);
		return (1);
	}
}
