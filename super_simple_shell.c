#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

extern char **environ;

int main()
{
	int i;

	for (i = 0; i < 5; i++)
	{
		pid_t pid = fork();

		if (pid == -1)
		{
			perror("fork failed");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			char *args[] = {"/bin/ls", "-l", "/tmp", NULL};
			execve(args[0], args, environ);
			perror("execve failed");
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(NULL);
		}
	}

	return (0);
}
