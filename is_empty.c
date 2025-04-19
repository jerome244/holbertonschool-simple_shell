#include "shell.h"

int is_empty_or_whitespace(char *str)
{
    int i = 0;
    while (str[i])
    {
        if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
            return 0;
        i++;
    }
    return 1;
}
