#include "shell.h"

char *_getenv_value(const char *name)
{
	int i;
	size_t len;

	if (!name || !*name)
		return (NULL);

	len = strlen(name);
	for (i = 0; environ[i]; i++)
	{
		/* Match name=... format exactly */
		if (strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
			return (environ[i] + len + 1);
	}
	return (NULL);
}

