#include "shell.h"

char *find_command_in_path(char *command)
{
    char *path_env = getenv("PATH");
    char *path_copy = strdup(path_env);
    char *token, *full_path = NULL;
    struct stat st;

    if (!path_env || !path_copy)
        return NULL;
    token = strtok(path_copy, ":");
    while (token)
    {
        full_path = malloc(strlen(token) + strlen(command) + 2);
        if (!full_path)
        {
            free(path_copy);
            return NULL;
        }
        sprintf(full_path, "%s/%s", token, command);
        if (stat(full_path, &st) == 0 && (st.st_mode & S_IXUSR))
        {
            free(path_copy);
            return full_path;
        }
        free(full_path);
        full_path = NULL;
        token = strtok(NULL, ":");
    }
    free(path_copy);
    return NULL;
}
