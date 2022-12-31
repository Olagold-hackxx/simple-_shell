#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <error.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

void exec_err(char *file);
int print_prompt(int status);
size_t _getline(char *argv[]);
int exec_exe(char *path, char **arg, char **envp);




#endif  /* SHELL_H */

