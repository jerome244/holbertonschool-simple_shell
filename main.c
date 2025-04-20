#include "shell.h"
/**
 * main - main function.
 * Return: always 0.
 */
int main(void)
{
	char *buf = NULL;
	size_t buf_size = 0;
	int nread, i;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "#cisfun$ ", 9);
		nread = getline(&buf, &buf_size, stdin);
		if (nread == -1)
			break;
		if (buf[nread - 1] == '\n')
			buf[nread - 1] = '\0';
		if (buf[0] == '\0')
			continue;
		for (i = 0; buf[i]; i++)
			if (is_space(buf[i]))
				continue;
		if (!is_empty_or_whitespace(buf))
			pid_printer(buf);
	}
	free(buf);
	return (0);
}
