#include "shell.h"

void pid_printer(char *buf)
{
    pid_t child_pid;
    int status;
    char *av[2];
    char *token;
    const char *delim = " \t\r\n";
    
    token = strtok(buf, delim);
    while (token != NULL)
    {
        if (access(token, X_OK) == 0)
        {
            pid_t pid = fork();
            if (pid == 0)
            {
                char *argv[] = { token, NULL };
                execve(token, argv, NULL);
                perror("./shell");
                exit(EXIT_FAILURE);
            }
            else
            {
                wait(&status);
            }
        }
        else
            write(STDERR_FILENO, "./shell\n", 9);
        token = strtok(NULL, delim);
    }
}
