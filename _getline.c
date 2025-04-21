#include "shell.h"
/**
 * _getline - function to implement getline
 * Return: NULL
 */

char *_getline(void)
{
	char *buffer = NULL;
	size_t buf_size = 0;
	int checker;

	checker = getline(&buffer, &buf_size, stdin);
	if (checker == -1)
		free(buffer);
	else
		return (buffer);
	return (NULL);
}
