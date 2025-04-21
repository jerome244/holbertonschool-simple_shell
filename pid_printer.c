#include "shell.h"

void pid_printer(char **token, char **path)
{
	pid_t pid;
	char *temp, *command;
	int status, i = 0;

	pid = fork();
		if (pid == 0)
		{
			command = strdup(token[0]);
			execve(token[0], token, environ);

			while (path[i])
			{
				temp = malloc(strlen(path[i]) + strlen(command) + 1);
				if (!temp)
					exit(EXIT_FAILURE);
				strcpy(temp, path[i]);
				strcat(temp, "/");
				strcat(temp, command);
				free(token[0]);
				token[0] = strdup(temp);
				free(temp);
				execve(token[0], token, environ);
				i++;
			}
			printf("No such file or directory\n");
			exit(EXIT_FAILURE);
		}
		else
			wait(&status);
		for (i = 0; *(token + i); i++)
			free(*(token + i));
		free(token);
}
