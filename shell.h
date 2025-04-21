#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

extern char **environ;

void pid_printer(char **token, char **path);
char **tokenization(char *prompt, char *delim);
char *_getline(void);
char **pathfinder(void);
char **path_tokenizer(char *temp);
char *path_finder(char **environment);
int allocate_environment_memory(char **environment);

#endif
