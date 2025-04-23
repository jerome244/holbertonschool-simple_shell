#include "shell.h"

/**
 * cd - handles the 'cd' built-in command without using getenv()
 * @token: tokenized user input
 * Return: 0 on success, 1 on failure
 */
int cd(char **token)
{
	char *dir = token[1], cwd[1024];
	char *prev_dir = _getenv_value("PWD");

	if (!dir || strcmp(dir, "~") == 0)
		dir = _getenv_value("HOME");
	else if (strcmp(dir, "-") == 0)
	{
		dir = _getenv_value("OLDPWD");
		if (!dir)
			return (1);
		write(STDOUT_FILENO, dir, strlen(dir));
		write(STDOUT_FILENO, "\n", 1);
	}

	if (!dir || chdir(dir) != 0)
	{
		perror("cd");
		return (1);
	}

	if (prev_dir)
		setenv("OLDPWD", prev_dir, 1);
	if (getcwd(cwd, sizeof(cwd)))
		setenv("PWD", cwd, 1);

	return (0);
}
