#include "shell.h"

int main(void)
{
    char *buf = NULL;
    size_t buf_size = 0;
    ssize_t nread;
   
    while (1)
    {
        write(STDOUT_FILENO, "#cisfun$ ", 9);

        nread = getline(&buf, &buf_size, stdin);
        if (nread == -1)
        {
            write(STDOUT_FILENO, "\n", 1);  /*For clean exit on Ctrl+D*/
            break;
        }

        if (buf[nread - 1] == '\n')
            buf[nread - 1] = '\0';

        if (buf[0] == '\0')
            continue;

        pid_printer(buf);
    }

    free(buf);
    return 0;
}
