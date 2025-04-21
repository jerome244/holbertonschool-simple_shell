#include "shell.h"

char **path_tokenizer(char *temp)
{
        char *new;
        char **array = NULL;
        int i = 0;

        array = tokenization(temp, ":");
        if (!array)
                return (NULL);

        while (array[i])
        {
                new = malloc(strlen(array[i]) + 2);
                if (!new)
                        return NULL;

                strcpy(new, array[i]);
                strcat(new, "/");
                free(array[i]);
                array[i] = new;
                i++;
        }
	free(new);
    return (array);
}
