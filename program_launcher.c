#include "shell.h"

/**
  * program_launcher - launches a program from PATH directories
  * @token: command and arguments (tokenized)
  * @path: directories from PATH variable (each ends with '/')
  */

void program_launcher(char **token, char **path)
{
	pid_t pid = fork();
	char *cmd = NULL, *temp = NULL;
	int i, status;

	if (pid == 0) /* Child process */
	{
		cmd = strdup(token[0]);
		if (!cmd)
			exit(EXIT_FAILURE);

		execve(cmd, token, environ);

		for (i = 0; path[i]; i++) /* Try PATH directories */
		{
			temp = malloc(strlen(path[i]) + strlen(cmd) + 1);
			if (!temp)
				break;

			strcpy(temp, path[i]);
			strcat(temp, cmd);
			free(token[0]);
			token[0] = strdup(temp);
			free(temp);

			if (!token[0])
				break;

			execve(token[0], token, environ);
		}

		fprintf(stderr, "%s: command not found\n", cmd);
		free(cmd);
		for (i = 0; token[i]; i++) free(token[i]);
		free(token);
		exit(EXIT_FAILURE);
	}
	else if (pid > 0) /* Parent process */
	{
		wait(&status);
		for (i = 0; token[i]; i++) free(token[i]);
		free(token);
	}
}
