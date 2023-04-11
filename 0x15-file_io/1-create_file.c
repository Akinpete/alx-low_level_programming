#include "main.h"

/**
 * create_file - a function that creates a file
 *
 * @filename: name of file to create
 * @text_content: string to write to file
 *
 * Return: 1 on success OR -1 on failure
 */

int create_file(const char *filename, char *text_content)
{
	int req_file, write_check, words = 0;

	if (filename == NULL)
		return (-1);

	req_file = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
	if (req_file == -1)
		return (-1);

	if (text_content)
	{
		while (text_content[words] != '\0')
			words++;

		write_check = write(req_file, text_content, words);
		if (write_check == -1)
			return (-1);

	}

	close(req_file);
	return (1);


}
