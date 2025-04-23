#include "shell.h"

extern char **environ;

int _setenv(const char *name, const char *value, int overwrite)
{
    size_t len;
    char *new_var, **new_environ;
    int i, j;

    if (!name || !value)
        return (-1);

    len = strlen(name) + strlen(value) + 2;
    new_var = malloc(len);
    if (!new_var)

    sprintf(new_var, "%s=%s", name, value);

    for (i = 0; environ[i]; i++)
    {
        if (strncmp(environ[i], name, strlen(name)) == 0 && environ[i][strlen(name)] == '=')
        {
            if (!overwrite)
            {
                free(new_var);
                return 0;
            }

            free(environ[i]);
            environ[i] = new_var;
            return 0;
        }
    }

    new_environ = malloc(sizeof(char *) * (i + 2));
    if (!new_environ)
    {
        free(new_var);
        return -1;
    }

    for (j = 0; j < i; j++)
        new_environ[j] = environ[j];
    
    new_environ[i] = new_var;
    new_environ[i + 1] = NULL;
    environ = new_environ;

    return (0);
}
