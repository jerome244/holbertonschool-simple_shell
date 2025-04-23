#include "shell.h"

extern char **environ;

int cd(char **token)
{
    char *dir = token[1], cwd[1024];
    char *prev_dir;

    if (!dir || strcmp(dir, "~") == 0)
    {
        dir = _getenv_value("HOME");
        if (!dir)
        {
            /* Avoid printing the error message directly */
            return (1);
        }
    }

    else if (strcmp(dir, "-") == 0)
    {
        prev_dir = _getenv_value("OLDPWD");
        if (!prev_dir)
        {
            write(STDERR_FILENO, "cd: OLDPWD not set\n", 20);
            return (1);
        }
        dir = prev_dir;
        write(STDOUT_FILENO, dir, strlen(dir));
        write(STDOUT_FILENO, "\n", 1);
    }

    if (chdir(dir) != 0)
    {
        perror("cd");
        return (1);
    }

    setenv("OLDPWD", _getenv_value("PWD"), 1);

    if (getcwd(cwd, sizeof(cwd)) != NULL)
        setenv("PWD", cwd, 1);

    return (0);
}
