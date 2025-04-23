#include "shell.h"

/**
 * builtin_setenv - handles the 'setenv' built-in
 * @token: array of arguments
 * Return: 0 on success, 1 on failure
 */
int builtin_setenv(char **token)
{
	if (!token[1] || !token[2])
	{
		write(STDERR_FILENO, "Usage: setenv VARIABLE VALUE\n", 30);
		return (1);
	}
	if (setenv(token[1], token[2], 1) != 0)
	{
		perror("setenv");
		return (1);
	}
	return (0);
}

/**
 * builtin_unsetenv - handles the 'unsetenv' built-in
 * @token: array of arguments
 * Return: 0 on success, 1 on failure
 */
int builtin_unsetenv(char **token)
{
	if (!token[1])
	{
		write(STDERR_FILENO, "Usage: unsetenv VARIABLE\n", 26);
		return (1);
	}
	if (unsetenv(token[1]) != 0)
	{
		perror("unsetenv");
		return (1);
	}
	return (0);
}
