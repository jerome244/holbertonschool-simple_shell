#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

void pid_printer(char *buf);
int is_space(char c);
int is_empty_or_whitespace(char *str);

#endif
