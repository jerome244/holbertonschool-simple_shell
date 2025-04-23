#include "shell.h"

char **pathfinder(void)
{
	char **array = NULL, *path_val = NULL, *with_slash;
	int i;

	for (i = 0; environ[i]; i++)
	{
		char **pair = tokenization(environ[i], "=");
		if (!pair) continue;
		if (strcmp(pair[0], "PATH") == 0 && pair[1])
			path_val = strdup(pair[1]);
		free(pair[0]); free(pair[1]); free(pair);
		if (path_val) break;
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
