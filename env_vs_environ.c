#include "main.h"

int main(int argc, char **argv, char **env)
{
	printf("env: %p\n", (void *)env);
	printf("environ: %p\n", (void *)environ);
	
	return (0);
}
