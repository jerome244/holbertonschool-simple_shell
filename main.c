
#include "shell.h"

/**
 * main - main function
 *
 * Return: always 0
 */

int main(void)
{
	char *prompt = NULL, **token, **path;
	int i = 0, checker;
	size_t prompt_size = 0;

	path = pathfinder();
	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(1, ":) ", 3);
		checker = getline(&prompt, &prompt_size, stdin);
		if (checker == -1)
			break;
		token = tokenization(prompt, " \t\r\n");
		free(prompt);
		prompt = NULL;
		
		if (!*token)
		{
			free(token);
			continue;
		}
        pid_printer(token, path);
	}
	for (i = 0; *(path + i); i++)
		free(*(path + i));
	free(path);
	return (0);
}
