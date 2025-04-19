#include "shell.h"

/**
 * trim_whitespace - Trims leading and trailing whitespace from a string
 * @str: The string to trim
 * Return: Pointer to the trimmed string
 */

char *trim_whitespace(char *str)
{
	char *end;

	while (isspace((unsigned char)*str))
		str++;
	if (*str == 0)
		return str;
	end = str + strlen(str) - 1;
	while (end > str && isspace((unsigned char)*end))
		end--;
	*(end + 1) = '\0';
	return str;
}
