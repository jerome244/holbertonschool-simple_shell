#include "shell.h"

#define MAX_ARGS 64

void pid_printer(char *buf)
{
    pid_t pid;
    int status;
    char *argv[MAX_ARGS];
    char *token;
    int i = 0;
    
    token = strtok(buf, " \t\n");
    while (token != NULL && i < MAX_ARGS - 1)
    {
        argv[i++] = token;
        token = strtok(NULL, " \t\n");
    }
    argv[i] = NULL;
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
