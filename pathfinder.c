#include "shell.h"

/**
 * pathfinder - function to locate file in the path
 * Return: array
 */

char **pathfinder(void)
{
        char **path_token = NULL;
        char **environment;
        char *temp = NULL;
        int i, num = 0;
        int env_count = 0;

        while (environ[env_count])
    		env_count++;
    	environment = malloc(sizeof(char *) * (env_count + 1));
    	if (!environment)
        	return NULL;
    	num = allocate_environment_memory(environment);
    	temp = path_finder(environment);
    	path_token = path_tokenizer(temp);
        if (temp)
                free(temp);
        for (i = 0; i < num; i++)
                free(environment[i]);
        free(environment);
        return (path_token);
}
