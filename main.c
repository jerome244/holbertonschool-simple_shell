#include "shell.h"

/**
 * main - main function of the simple_shell app
 * Return: always 0
 */
#define MAX_ARGS 64

int main(void)
{
	char *buf = NULL;
	size_t buf_size = 0;
	int i = 0;
	char *argv[MAX_ARGS];
    	char *token;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "#cisfun$ ", 9);
		getline(&buf, &buf_size, stdin);
		token = strtok(buf, " \t\n");
        	while (token != NULL && i < MAX_ARGS - 1)
        	{
            		argv[i++] = token;
            		token = strtok(NULL, " \t\n");
        	}
		argv[i] = NULL;
		if (argv[0] == NULL)
			continue;
		pid_printer(argv);
	}
	free(buf);
	return (0);
}
