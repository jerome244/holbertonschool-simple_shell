#include "shell.h"

/**
 * main - main function of the shell
 * Return: always 0
 */
int main(void)
{
	char *prompt = NULL, **token = NULL, **commands = NULL;
	char **path = pathfinder();
	int last_status = 0, i;

	if (!path)
		return (1);

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);

		if (!(prompt = _getline()))
			break;

		commands = tokenization(prompt, ";");
		if (!commands)
		{
			free(prompt);
			continue;
		}
		free(prompt);

		for (i = 0; commands && commands[i]; i++)
		{
			token = tokenization(commands[i], " \t\r\n");
			if (!token || !*token)
			{
				free_array(token);
				continue;
			}

			if (!strcmp(token[0], "exit"))
			{
				free_array(token);
				free_array(commands);
				free_array(path);
				exit(last_status);
			}
			else if (!strcmp(token[0], "env"))
				print_env();
			else if (!strcmp(token[0], "cd"))
				last_status = cd(token);
			else if (!strcmp(token[0], "setenv"))
				last_status = builtin_setenv(token);
			else if (!strcmp(token[0], "unsetenv"))
				last_status = builtin_unsetenv(token);
			else
				last_status = program_launcher(token, path);

			free_array(token);
		}
		free_array(commands);
	}

	free_array(path);
	return (0);
}
