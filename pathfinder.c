#include "shell.h"

/**
 * pathfinder - function to locate file paths in the PATH environment variable
 * Return: array of directories in the PATH, each ending with a '/'
 */

char **pathfinder(void)
{
	char *path_env, *temp, **array;
	int i;
	char *new;

	path_env = getenv("PATH");
	if (!path_env)
		return (NULL);

	temp = strdup(path_env); /* Duplicate to avoid modifying original */
	if (!temp)
		return (NULL);

	array = tokenization(temp, ":"); /* Split by ':' */
	free(temp);
	if (!array)
		return (NULL);
	for (i = 0; array[i]; i++)
	{
		new = malloc(strlen(array[i]) + 2);  /* +1 for '/' and +1 for '\0' */
		if (!new)
			return (NULL);
		strcpy(new, array[i]);
		strcat(new, "/");
		free(array[i]);
		array[i] = new;
	}
	return (array);
}
