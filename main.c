#include "shell.h"

/**
 * main - main function of the shell
 *
 * Return: always 0
 */
int main(void)
{
	char *prompt = NULL, **token = NULL, **path = NULL;
	int i = 0;

	path = pathfinder();
	if (!path)
		return (1); /* Exit if path couldn't be built */

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);

		prompt = _getline();
		if (!prompt)
			break;

		token = tokenization(prompt, " \t\r\n");
		free(prompt);

		if (!token || !*token)
		{
			free_array(token);
			continue;
		}

		if (strcmp(token[0], "exit") == 0)
		{
			free_array(token);
			free_array(path);
			if (token[1] != NULL)
				exit(2);
			else
				exit(0);
		}

		pid_printer(token, path);
	}

	free_array(path);
	return (0);
}
