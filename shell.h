#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

extern char **environ;

void program_launcher(char **token, char **path);
char **tokenization(char *prompt, char *delim);
char *_getline(void);
char **pathfinder(void);
void free_array(char **array);

#endif
