#include "shell.h"

/*
 * _exit - function to implement the exit command.
 * @status: code status.
 */

void _exit(int status)
{
	if (status == 0)
		printf("OK\n");
        exit(status);
}
