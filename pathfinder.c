#include "shell.h"

/**
 * pathfinder - function to locate file in the path
 * Return: array of path tokenized
 */

char **pathfinder(void)
{
	char **array = NULL, *path_val = NULL, *with_slash, **token_path;
	int i;

	for (i = 0; environ[i]; i++)
	{
		token_path = tokenization(environ[i], "=");
		if (!token_path) 
			continue;
		if (strcmp(token_path[0], "PATH") == 0 && token_path[1])
			path_val = strdup(token_path[1]);
		free(token_path[0]); 
		free(token_path[1]); 
		free(token_path);
		if (path_val) 
			break;
	}

	if (!path_val)
		return (NULL);

	array = tokenization(path_val, ":");
	free(path_val);
	if (!array)
		return (NULL);

	for (i = 0; array[i]; i++)
	{
		with_slash = malloc(strlen(array[i]) + 2);
		if (!with_slash)
			return (NULL);
		strcpy(with_slash, array[i]);
		strcat(with_slash, "/");
		free(array[i]);
		array[i] = with_slash;
	}

	return (array);
}
