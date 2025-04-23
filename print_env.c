#include "shell.h"

/**
 * print_env - prints the current environment
 */

void print_env(void)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
}
