#include "shell.h"


 /**
  * main - main function of the shell
  * Return: always 0
  */
 int main(void)
 {
  	char *prompt = NULL, **token = NULL, **path = pathfinder();
  	int last_status = 0, i;

  	if (!path)
  		return (1);

  	while (1)
  	{
  		if (isatty(STDIN_FILENO))
  			write(STDOUT_FILENO, "$ ", 2);

  		if (!(prompt = _getline()))
  			break;

  		token = tokenization(prompt, " \t\r\n");
  		free(prompt);

  		if (!token || !*token)
  		{
  			free_array(token);
  			continue;
  		}
		for (i = 0; token[i]; i++)
{
    if (strcmp(token[i], "$?") == 0)
    {
        char status_str[12];
        sprintf(status_str, "%d", last_status);
        free(token[i]);
        token[i] = strdup(status_str);
        if (!token[i])
        {
            perror("strdup");
        }
    }
}


  		if (!strcmp(token[0], "exit"))
  		{
  			free_array(token);
  			free_array(path);
 			exit(last_status);
  		}

  		if (!strcmp(token[0], "env"))
  		{
  			print_env();
  			free_array(token);
  			continue;
  		}
		if (!strcmp(token[0], "cd"))
 			last_status = cd(token);
 		else if (!strcmp(token[0], "setenv"))
            		last_status = setenv_builtin(token);
		else if (!strcmp(token[0], "unsetenv"))
    			last_status = unsetenv_builtin(token);
		else
 			last_status = program_launcher(token, path);
  	}

  	free_array(path);
	return (0);
 }
