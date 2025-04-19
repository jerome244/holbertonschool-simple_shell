#include "shell.h"

#define MAX_ARGS 64

void pid_printer(char *buf)
{
    pid_t pid;
    int status;
    char *argv[2];
    char *token;
    const char *delim = " \t\r\n";
    int i = 0;
    
    token = strtok(buf, delim);
    while (token != NULL && i < MAX_ARGS - 1)
    {
	    if (access(token, X_OK) == 0)
	    {
	    	pid = fork();
            	if (pid == 0)
            	{
                	argv[i++] = token;
                	execve(argv[0], argv, NULL);
                	perror("./shell: No such file or directory");
                	exit(EXIT_FAILURE);
		}
            	else
            	{
                	wait(&status);
            	}
	    }
	    else
		    write(STDERR_FILENO, "./shell: No such file or directory\n", 35);
	    token = strtok(NULL, delim);
    }
}
