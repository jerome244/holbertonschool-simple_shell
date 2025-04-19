#include "shell.h"

/**
 * main - main function of the simple_shell app
 * Return: always 0
 */

int main(void)
{
	char *buf = NULL;
	size_t n, buf_size = 0;

	while (1)
	{
		write(STDOUT_FILENO, "#cisfun$ ", 9);
		n = getline(&buf, &buf_size, stdin);
		if (n == -1)
		{
			write(STDOUT_FILENO, "\n", 1);
			break;
		}
		if (buf[n - 1] == '\n')
			buf[n - 1] = '\0';
		if (buf[0] == '\0')
			continue;
		pid_printer(buf);
	}
	free(buf);
	return (0);
}
