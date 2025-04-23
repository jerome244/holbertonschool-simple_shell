#include "shell.h"

/**
 * main - main function of the shell
 * Return: always 0
 */
int main(void)
{
	char *prompt = NULL, **token = NULL, **path = pathfinder();
	int last_status = 0;

	if (!path)
		return (1);

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);

		if (!(prompt = _getline()))
			break;

		token = tokenization(prompt, " \t\r\n");
		free(prompt);

		if (!token || !*token)
		{
			free_array(token);
			continue;
		}

		if (!strcmp(token[0], "exit"))
		{
    			free_array(token);
    			free_array(path);
    			if (isatty(STDIN_FILENO))
        			exit(last_status);
    			else
        			exit(2);
		}

		if (!strcmp(token[0], "env"))
		{
			print_env();
			free_array(token);
			continue;
		}

		last_status = program_launcher(token, path);
		free_array(token);
	}

	free_array(path);
	return (0);
}
