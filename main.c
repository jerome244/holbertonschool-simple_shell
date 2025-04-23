#include "shell.h"

/**
   * main - main function of the shell
   * Return: always 0
   */
int main(void)
{
	char *prompt = NULL, **token = NULL, **path = pathfinder();
   	int last_status = 0, exit_status, i;

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

   		if (!strcmp(token[0], "exit"))
		{
    			exit_status = last_status;

    			if (token[1])
    			{
        			i = 0;

                		if (token[1][0] == '-' || token[1][0] == '\0')
        			{
            				fprintf(stderr, "./hsh: 1: exit: Illegal number: %s\n", token[1]);
            				free_array(token);
            				free_array(path);
            				exit(2);
        			}

        			while (token[1][i])
        			{
            				if (token[1][i] < '0' || token[1][i] > '9')
            				{
                				fprintf(stderr, "./hsh: 1: exit: Illegal number: %s\n", token[1]);
                				free_array(token);
                				free_array(path);
                				exit(2);
					}
            				i++;
        			}

        			exit_status = str_to_int(token[1]);
    			}

    			free_array(token);
    			free_array(path);
    			exit(exit_status);
		}


   		if (!strcmp(token[0], "env"))
   		{
   			print_env();
   			free_array(token);
   			continue;
   		}
 		else if (!strcmp(token[0], "cd"))
  			last_status = cd(token);
  		else
  			last_status = program_launcher(token, path);
   	}

   	free_array(path);
 	return (0);
}
