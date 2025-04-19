#include "shell.h"

void pid_printer(char *buf)
{
    pid_t pid;
    int status;
    char *argv[2];
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
                argv[0] = token;
		argv[1] = NULL;
                execve(token, argv, NULL);
                perror("./shell: No such file or directory");
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
