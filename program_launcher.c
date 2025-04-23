#include "shell.h"

/** program_launcher - launch app from path file.
 * @token: string token.
 * @path: array tokenized of the path.
 */

int program_launcher(char **token, char **path)
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
			exit(2);
		}
		else if
		{
			wait(&status);
			return (0);
		}
		else
		{
			perror("fork failed");
			return (2);
		}
}
