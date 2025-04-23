#include "shell.h"

/**
 * pid_printer - launches a program from PATH directories
 * @token: command and arguments (tokenized)
 * @path: directories from PATH variable (each ends with '/')
 */

void pid_printer(char **token, char **path)
{
	pid_t pid;
	char *temp = NULL, *command = NULL;
	int status, i = 0;

	pid = fork();
	if (pid == 0)
	{
		command = strdup(token[0]);
		if (!command)
			exit(EXIT_FAILURE);

		execve(token[0], token, environ);
		/* Try each path directory */
		while (path[i])
		{
			free(token[0]);
			temp = malloc(strlen(path[i]) + strlen(command) + 1);
			if (!temp)
			{
				free(command);
				exit(EXIT_FAILURE);
			}
			strcpy(temp, path[i]);
			strcat(temp, command);

			token[0] = strdup(temp);
			free(temp);

			if (!token[0])
			{
				free(command);
				exit(EXIT_FAILURE);
			}

			execve(token[0], token, environ);
			i++;
		}

		/* Command not found in any path */
		fprintf(stderr, "%s: command not found\n", command);
		free(command);
		for (i = 0; token[i]; i++)
			free(token[i]);
		free(token);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status);
		for (i = 0; token[i]; i++)
			free(token[i]);
		free(token);
	}
}
