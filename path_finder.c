#include "shell.h"

char *path_finder(char **environment)
{
        char **array = NULL;
        int i, j = 0;
        char *temporary;

        while (environment[j])
                {
                        array = tokenization(environment[j], "=");

                        if (!strcmp(*array, "PATH"))
                        {
                                if (!array[1])
                                        break;

                                temporary = strdup(array[1]);


                                for (i = 0; i < 2; i++)
                                {
                                        free(array[i]);
                                }
                                free(array);
                                break;
                        }
                        for (i = 0; i < 2; i++)
                                free(array[i]);
                        free(array);
                        j++;
                }
        return (temporary);
}
