#include "main.h"

char *_getenv(const char *name)
{
	int len = strlen(name);
	for (char **env = environ; *env; env++)
	{
		if (strncmp(*env, name, len) == 0 && (*env)[len] == '=')
			return (*env + len + 1);
	}
	return (NULL);
}
