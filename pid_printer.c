#include "shell.h"

void pid_printer(char **argv)
{
    pid_t pid;

    if (access(argv[0], X_OK) == 0)
        {
            pid = fork();
            if (pid == 0)
            {
                execve(argv[0], argv, NULL);
                perror("./shell");
                exit(EXIT_FAILURE);
            }
            else
            {
                wait(NULL);
            }
        }
        else
        {
            perror("./shell");
        }
}
