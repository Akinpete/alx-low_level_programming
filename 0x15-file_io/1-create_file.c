#include "main.h"

/**
 * create_file - creates a file
 * @filename: filename.
 * @text_content: content writed in the file.
 *
 * Return: 1 if it succeeds. -1 if it fails.
 */
int create_file(const char *filename, char *text_content)
{
	int fd;
	int nletters = 0;
	int rwr;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0600);

	if (fd < 0)
		return (-1);

	while (text_content && *(text_content + nletters)) 
		nletters++;

	rwr = write(fd, text_content, nletters);
	
	close(fd);

	if (rwr < 0)
		return (-1);
	return (1);
}
