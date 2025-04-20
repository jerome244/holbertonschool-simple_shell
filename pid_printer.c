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
	char *cmd_path = NULL;

	token = strtok(buf, delim);
	while (token != NULL)
	{
		argv[i++] = token;
		token = strtok(NULL, delim);
	}
	argv[i] = NULL;
	if (access(argv[0], X_OK) == 0)
            cmd_path = strdup(argv[0]);
    else
        cmd_path = find_command_in_path(argv[0]);
    if (cmd_path == NULL)
        fprintf(stderr, "./shell: %s: command not found\n", argv[0]);
    else
    {
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
}
