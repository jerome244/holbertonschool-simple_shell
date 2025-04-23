#include "shell.h"

extern char **environ;

/**
 * setenv_builtin - Implements the setenv command.
 * @token: Array of strings containing the command and arguments.
 *
 * Return: 0 on success, 1 on failure.
 */
int setenv_builtin(char **token)
{
    if (!token[1])
    {
        write(STDERR_FILENO, "Usage: setenv VARIABLE [VALUE]\n", 31);
        return (1);
    }

    if (_setenv(token[1], token[2] ? token[2] : "", 1) == -1)
    {
        perror("setenv");
        return (1);
    }
    return (0);
}

/**
 * unsetenv_builtin - Implements the unsetenv command.
 * @token: Array of strings containing the command and the variable name.
 *
 * Return: 0 on success, 1 on failure.
 */
int unsetenv_builtin(char **token)
{
    if (!token[1])
    {
        write(STDERR_FILENO, "Usage: unsetenv VARIABLE\n", 24);
        return (1);
    }

    if (unsetenv(token[1]) == -1)
    {
        perror("unsetenv");
        return (1);
    }

    return (0);
}

/**
 * _getenv_value - Get the value of an environment variable.
 * @name: Name of the environment variable.
 *
 * Return: The value of the environment variable, or NULL if not found.
 */
char *_getenv_value(const char *name)
{
    int i;
    size_t len;

    if (!name || !*name)
        return (NULL);

    len = strlen(name);
    for (i = 0; environ[i]; i++)
    {
        /* Match name=... format exactly */
        if (strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
            return (environ[i] + len + 1);
    }
    return (NULL);
}
