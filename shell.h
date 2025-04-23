#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

extern char **environ;

void pid_printer(char **token, char **path);
char **tokenization(char *prompt, char *delim);
char *_getline(void);
char **pathfinder(void);
void free_array(char **array);

#endif
