#include "shell.h"

char **pathfinder(void)
{
    char *path_env = getenv("PATH");
    char **array;
    int i = 0;

    if (!path_env)
        return NULL;

    array = tokenization(path_env, ":");

    while (array[i])
    {
        char *new = malloc(strlen(array[i]) + 2);
        strcpy(new, array[i]);
        strcat(new, "/");
        free(array[i]);
        array[i] = new;
        i++;
    }

    return array;
}

