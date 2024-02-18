#ifndef SHELL_HEADER_H
#define SHELL_HEADER_H

#include <stdio.h>
#include <string.h>
extern char **environ;

char *_getenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);
void print_env(void);
void print_path(void);

#endif
