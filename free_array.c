#include "shell.h"

/**
 * free_array - Frees an array of strings
 * @array: Array of strings to be freed
 */
void free_array(char **array)
{
    int i = 0;

    if (!array)
        return;

    while (array[i])
    {
        free(array[i]);
        i++;
    }

    free(array);
}
