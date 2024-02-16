#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *line = NULL;
	size_t len = 0;

	printf("#cisfun$ ");

	ssize_t read = getline(&line, &len, stdin);

	if (read == -1)
	{
		printf("Error reading input\n");
		free(line);
		exit(EXIT_FAILURE);
	}

	printf("%s", line);

	free(line);

	return (0);
}
