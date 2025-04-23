#include "shell.h"

/**
 * print_env - function to print environment variables
 */
void print_env(void)
{
    int i = 0;

    while (environ[i])
    {
        write(STDOUT_FILENO, environ[i], strlen(environ[i]));
        write(STDOUT_FILENO, "\n", 1);
        i++;
    }
}
