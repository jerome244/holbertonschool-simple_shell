#include "shell.h"

/**
 * main - main function of the shell program
 *
 * Return: always 0
 */
int main(void)
{
    char *prompt, **token, **path;

    path = pathfinder();
    if (!path)
        return (1);

    while (1)
    {
        if (isatty(STDIN_FILENO))
            write(1, ":) ", 3);

        prompt = _getline();
        if (!prompt)
            break;

        token = tokenization(prompt, " \t\r\n");
        free(prompt);

        if (*token)
        {
            if (strcmp(token[0], "exit") == 0)
            {
                free_array(token);
                free_array(path);
                exit(0);
            }

            program_launcher(token, path);
        }

        free_array(token);
	token = NULL;
    }

    free_array(path);
    return (0);
}
