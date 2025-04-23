#include "shell.h"

/**
 * _atoi - Convert a string to an integer
 * @s: The string to convert
 * Return: The integer value, or 0 if no valid number
 */
int _atoi(char *s)
{
    int i = 0, result = 0, sign = 1;

    if (!s)
        return (0);

    /* Skip whitespace */
    while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
        i++;

    /* Check for sign */
    if (s[i] == '-' || s[i] == '+')
    {
        if (s[i] == '-')
            sign = -1;
        i++;
    }

    /* Convert to int */
    while (s[i] >= '0' && s[i] <= '9')
    {
        result = result * 10 + (s[i] - '0');
        i++;
    }

    return (sign * result);
}
