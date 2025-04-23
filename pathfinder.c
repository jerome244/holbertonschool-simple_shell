#include "shell.h"
 
 /**
  * pathfinder - function to locate file in the path
  * Return: array
  */

 char **pathfinder(void)
 {
 	char **array = NULL;
 	char **environment = malloc(sizeof(char *) * 64);
 	char *new, *temp = NULL;
 	int i, j = 0, num = 0;

 	while (environ[j])
 	{
 		environment[j] = malloc(strlen(environ[j]) + 1);
 		strcpy(environment[j], environ[j]);
 		j++;
 		num++;
 	}
 	j = 0;


 	while (environment[j])
 	{
 		array = tokenization(environment[j], "=");
 		if (!strcmp(*array, "PATH"))
 		{
 			if (!*(array + 1))
 				break;
 			temp = strdup(*(array + 1));
 			for (i = 0; i < 2; i++)
 				free(*(array + i));
 			free(array);
 			break;
 		}
 		for (i = 0; i < 2; i++)
 			free(*(array + i));
 		free(array);
 		j++;
 	}

 	array = tokenization(temp, ":");
		if (!array)
 		return (NULL);
 	i = 0;
 	while (array[i])
	{
		new = malloc(strlen(array[i]) + 2);
		if (!new)
 			return (NULL);
		strcpy(new, array[i]);
 		strcat(new, "/");
 		free(array[i]);
 		array[i] = new;
 		i++;
 	}

 	if (temp)
 		free(temp);
 	for (i = 0; i < num; i++)
 		free(environment[i]);
 	free(environment);
 	return (array);
 }
