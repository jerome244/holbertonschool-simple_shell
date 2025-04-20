#include "shell.h"
/**
 * pid_printer - check and print pid.
 * @buf: inputted string from user.
 */
void pid_printer(char *buf)
{
	pid_t pid;
	int status;
	char *argv[64];
	char *token;
	const char *delim = " \t\r\n";
	int i = 0;

	token = strtok(buf, delim);
	while (token != NULL)
	{
		argv[i++] = token;
		token = strtok(NULL, delim);
	}
	argv[i] = NULL;
	pid = fork();
	if (pid == 0)
	{
		execve(argv[0], argv, NULL);
		perror("./shell: o such file or directory");
		exit(EXIT_FAILURE);
	}
	else
		wait(&status);
}
