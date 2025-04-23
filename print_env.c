#include "shell.h"
 
 /**
  * print_env - prints the current environment
  */
 
 void print_env(void)
 {
 	int i = 0;
 
	if (!environ)
        	return;

 	while (environ[i])
    	{
        	if (environ[i] != NULL) 
		{
            		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
            		write(STDOUT_FILENO, "\n", 1);
        	}
        	i++;
   	}
}
