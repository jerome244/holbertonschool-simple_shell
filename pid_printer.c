#include "shell.h"

/** pid_printer - launch app from path file.
 * @token: string token.
 * @path: array tokenized of the path.
 */

void pid_printer(char **token, char **path)
{
	pid_t pid;
	char *temp, *command;
	int status, i = 0;

	pid = fork();
		if (pid == 0)
		{
			command = strdup(token[0]);
			while (path[i])
			{
				execve(token[0], token, environ);
                                temp = malloc(strlen(path[i]) + strlen(command) + 1);
                                strcpy(temp, path[i]);
                                strcat(temp, command);
                                free(token[0]);
                                token[0] = strdup(temp);
                                free(temp);
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
