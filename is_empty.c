#include "shell.h"
/**
 * is_empty_or_whitespace - check input string.
 * @str: input buffer.
 * Return: 0 false, 1 true.
 */
int is_empty_or_whitespace(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}
