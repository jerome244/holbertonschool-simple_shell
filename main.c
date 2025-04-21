#include "shell.h"

/**
 * main - main function
 *
 * Return: always 0
 */

int main(void)
{
	char *prompt, **token, **path;
	int i = 0;

	path = pathfinder();
	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(1, ":) ", 3);
		prompt = _getline();
		if (!prompt)
			break;
		token = tokenization(prompt, " \t\r\n");
		free(prompt);
		if (!*token)
		{
			free(token);
			continue;
		}
		if (strcmp(token[0], "exit") == 0)
                {
                        if (token[1] != NULL)
                                _exit(2);
                        else
			{
				if (!isatty(STDIN_FILENO))
					write(1, "OK", 2);
                                _exit(0);
			}
                }
        	pid_printer(token, path);
	}
	for (i = 0; *(path + i); i++)
		free(*(path + i));
	free(path);
	return (0);
}
