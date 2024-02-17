#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>

void signal_handler(int signal)
{
	if (signal == SIGINT)
	{
		printf("\n#cisfun$ ");
		fflush(stdout);
	}
}

extern char **environ;

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char *argv[2];
	argv[1] = NULL;
	
	signal(SIGINT, signal_handler);
	while (1)
	{
		printf("#cisfun$ ");
		read = getline(&line, &len, stdin);

		if (read <= 0)
			break;
		line[strcspn(line, "\n")] = 0;

		if (strcmp(line, "exit") == 0)
			break;

		argv[0] = line;

		pid_t pid = fork();

		if (pid == 0)
		{
			execve(argv[0], argv, environ);
			perror("execve");
			exit(EXIT_FAILURE);
		}
		else if (pid > 0)
		{
			wait(NULL);
		}
		else
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
	}
	free(line);
	return (0);
}
