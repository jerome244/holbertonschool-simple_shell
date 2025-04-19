#include "shell.h"

int is_empty_line(const char *line)
{
    while (*line)
    {
        if (!isspace(*line))
            return 0;
        line++;
    }
    return 1;
}
