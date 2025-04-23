#include "shell.h"

/**
 * free_array - Frees a NULL-terminated array of strings
 * @array: the array to free
 */

void free_array(char **array)
{
	int i;

	if (!array)
		return;
	for (i = 0; array[i]; i++)
		free(array[i]);
	free(array);
}
