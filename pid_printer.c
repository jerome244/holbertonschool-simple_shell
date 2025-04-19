#include "shell.h"

/**
 * pid_printer - print the pid status
 * @buf: take the user input for checking argument
 */

void pid_printer(char *buf)
{
	pid_t child_pid;
	int status;
	char *av[2];

	child_pid = fork();
	if (child_pid < 0)
	{
		perror("Error");
	}

	else if (child_pid == 0)
	{
		av[0] = buf;
		av[1] = NULL;

		execve(buf, av, NULL);
		perror("./shell");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status);
	}
}
