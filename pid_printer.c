#include "shell.h"

void pid_printer(char **argv)
{
    pid_t pid;
    int status;

            pid = fork();
            if (pid == 0)
            {
                execve(argv[0], argv, NULL);
                perror("./shell");
		exit(EXIT_FAILURE);
            }
            else
                wait(&status);
}
