#include "shell.h"

/**
 * builtin_cd - handles the 'cd' built-in command
 * @token: tokenized user input
 * Return: 0 on success, 1 on failure
 */

int cd(char **token)
{
    char *dir = token[1], cwd[1024];
    char *prev_dir;

    if (!dir || strcmp(dir, "~") == 0)
        dir = getenv("HOME");

    else if (strcmp(dir, "-") == 0)
    {
        prev_dir = getenv("OLDPWD");
        if (!prev_dir)
        {
            fprintf(stderr, "cd: OLDPWD not set\n");
            return (1);
        }
        printf("%s\n", prev_dir);
        dir = prev_dir;
    }

    if (chdir(dir) != 0)
    {
        perror("cd");
	return (1);
    }

    setenv("OLDPWD", getenv("PWD"), 1);

    if (getcwd(cwd, sizeof(cwd)) != NULL)
        setenv("PWD", cwd, 1);

    return (0);
}
