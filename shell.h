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
size_t _getline(char **argv);
size_t readline(char **argv);
int exec_exe(char *path, char **arg, char **envp);
ssize_t read(int fd, void *buf, size_t count);
void free_mem(char *mem_ptr, int mem_len);
char *init_mem(char *arg, size_t mem_len);
char **ptr_malloc(size_t mem_len);
char *chr_malloc(size_t mem_len);
char *_strncat(char *dest, char *src, size_t n);
char *_strcat(char *dest, char *src);
int _strncmp(char *s1, char *s2, size_t n);
int _strcmp(char *s1, char *s2);
char *_strncpy(char *dest, const char *src, size_t n);
size_t _strlen(char *s);
char *strformat(char *str,size_t str_size);

#endif  /* SHELL_H */