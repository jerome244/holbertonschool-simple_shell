#include <stdio.h>
#include <unistd.h>

/**
 * main - displays process ID and parent process ID
 * Return: 0
 */

int main (void)
{
	pid_t my_PID = getpid();
	printf("child %u\n", my_PID);
	
	pid_t my_PPID = getppid();
	printf("parent %u\n", my_PPID);

	return (0);
}
