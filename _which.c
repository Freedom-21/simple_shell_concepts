#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	struct stat buf;
	char *filename = argv[1];
	char *path = getenv("PATH");
	char *token = strtok(path, ":");

	while (token != NULL)
	{
		char fullPath[1024];
		snprintf(fullPath, sizeof(fullPath), "%s/%s", token, filename);
		if (stat(fullPath, &buf) == 0)
		{
			printf("Found: %s\n", fullPath);
			return (0);
		}
		token = strtok(NULL, ":");
	}
	printf("%s not found in PATH\n", filename);
	return (1);
}
