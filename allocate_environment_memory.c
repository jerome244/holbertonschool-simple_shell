#include "shell.h"

/**
 * allocate_environment_memory - cpy same memory as environ.
 * @environment: our receiver allocated space variable.
 * Return: return the count of memory space.
 */

int allocate_environment_memory(char **environment)
{
        int i = 0, count = 0;

        while (environ[i])
        {
                environment[i] = malloc(strlen(environ[i]) + 1);
                strcpy(environment[i], environ[i]);
                i++;
                count++;
        }

        return (count);
}
