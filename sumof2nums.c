#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int n1, n2, sum;

	if (argc != 3)
	{
		printf("Error: usage %s <n1> <n2>\n", argv[0]);
		return (1);
	}

	n1 = atoi(argv[1]);
	n2 = atoi(argv[2]);
	sum = n1 + n2;

	printf("The result of %d + %d = %d\n", n1, n2, sum);
	return (0);
}
