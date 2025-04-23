#include "shell.h"

/**
 * tokenization - tokenize a string.
 * @prompt: inputted string from user's prompt.
 * @delim: character to search first occurence.
 * Return: a new token.
 */

char **tokenization(char *prompt, char *delim)
{
	char *token;
	char **new_token;
	int i = 0;

	if (prompt == NULL || prompt[0] == '\0')
		return (NULL);

	new_token = malloc(strlen(prompt) * sizeof(char *));
	token = strtok(prompt, delim); 
	while (token != NULL)
	{
		new_token[i] = strdup(token);
		if (!new_token[i])
		{
			free(new_token[i]);
			exit(1);
		}
		i++;
		token = strtok(NULL, delim);
	}
	new_token[i] = NULL;
	return (new_token);
}
