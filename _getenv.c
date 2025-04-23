#include "shell.h"

/**
 * _getenv_value - manually gets an environment variable value from environ
 * @name: name of the environment variable
 * Return: pointer to the value, or NULL if not found
 */

extern char **environ;

char *_getenv_value(const char *name)
{
	int i;
	size_t len = strlen(name);

	for (i = 0; environ[i]; i++)
	{
		if (strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
		return (environ[i] + len + 1);
	}
	return (NULL);
}
