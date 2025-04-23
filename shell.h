#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

extern char **environ;

int program_launcher(char **token, char **path);
char **tokenization(char *prompt, char *delim);
char *_getline(void);
char **pathfinder(void);
void free_array(char **array);
void print_env(void);
int cd(char **token);
char *_getenv_value(const char *name);
int unsetenv_builtin(char **token);
int setenv_builtin(char **token);
int _setenv(const char *name, const char *value, int overwrite);
int _atoi(char *s);

#endif
