#include "shell.h"

void pid_printer(char *buf)
{
    pid_t pid;
    int status;
    char *argv[2];

    pid = fork();
        if (pid < 0)
        {
            perror("fork");
        }

        if (pid == 0)
        {
            argv[0] = buf;
            argv[1] = NULL;
            execve(buf, argv, NULL);
            perror("./shell");
            exit(EXIT_FAILURE);
        }
        else
        {
            wait(&status);
        }
}
