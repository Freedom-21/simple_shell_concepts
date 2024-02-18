#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int ac, char **av) {
    struct stat st;
    if (ac < 2) {
        printf("Usage: %s path_to_file ...\n", av[0]);
        return 1;
    }
    for (unsigned int i = 1; av[i]; i++) {
        if (stat(av[i], &st) == 0) {
            printf("%s: FOUND\n", av[i]);
        } else {
            printf("%s: NOT FOUND\n", av[i]);
        }
    }
    return 0;
}

