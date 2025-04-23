#include "shell.h"

int program_launcher(char **token, char **path)
{
	pid_t pid;
	int status = 0, i = 0;
	char *cmd = NULL, *temp = NULL;

	pid = fork();
	if (pid == 0)
	{
		cmd = strdup(token[0]);
		if (!cmd)
			exit(EXIT_FAILURE);

		execve(cmd, token, environ);

		for (i = 0; path[i]; i++)
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
		exit(127);
	}
	else if (pid > 0)
	{
		wait(&status);
		for (i = 0; token[i]; i++) free(token[i]);
		free(token);
		return WEXITSTATUS(status);
	}

	return 1;
}
