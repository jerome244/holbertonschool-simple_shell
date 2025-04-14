#include <stdio.h>
#include <unistd.h>

/**
 * getline - waits for the user to enter a command, and prints it on the next line
 * Return: number of characters read, delimiters included but excluding NULL
 * (or -1 if failure in reading process)
 */

ssize_t getline(char **lineptr, size_t *n, FILE *stream)
{

