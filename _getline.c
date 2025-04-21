#include "shell.h"
/**
 * _getline - function to implement getline
 * Return: NULL
 */

char *_getline(void)
{
	size_t buf_size = 0;
	int checker;

	checker = getline(&buf, &buf_size, stdin);
	if (checker == -1)
		free(buf);
	else
		return (buf);
	return (NULL);
}
