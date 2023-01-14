#include "shell.h"

/**
 * _getline - get line from stdin in interactive mode
 * @argv: ptr to ptr holding progam name
 * Return: read size
 */

size_t _getline(char **argv)
{
	char *buf = NULL, *path;
	size_t buf_size = 100;
	ssize_t read_size;
	char *copied, **arg, *token, *delim = " ", **envp = NULL;
	int len, i;

        /*read user input from stdin */
	read_size = getline(&buf, &buf_size, stdin);
	if (read_size < 0)
		perror(argv[0]);

	arg = ptr_malloc(20);

	copied = chr_malloc(read_size);
	path = chr_malloc(read_size);

	if (path == NULL)
	{
		free(path);
		exit(EXIT_FAILURE);
	}
	init_mem(path, read_size);
	init_mem(copied, read_size);
	/*copy input from getline */
	_strncat(copied, buf, read_size - 1);
	copied[read_size - 1] = '\0';
	copied = strformat(copied, read_size);
	token = strtok(copied, delim);
	i = 0;
	arg[0] = token;
	while (arg[i])
	{
		i++;
		arg[i] = strtok(NULL, delim);
	}
	strcpy(path, arg[0]);
	//_strcat(path, token);
	exec_exe(path, arg, envp);
	//free(buf);
	//free(copied);
	//free(path);
	return (read_size);
}

/**
 * readline - read from terminal in non interactive mode
 * @argv: ptr to ptr holding progam name
 * Return: read size
 */

size_t readline(char **argv)
{
	int token, i;
	size_t count = 100;
	char *buf, *arg[50], *copied, *delim = " ";
	ssize_t read_size;

	/*alloc memory for buf*/
	buf = malloc(sizeof(char) * count);
	if (buf == NULL)
	{
		free(buf);
		exit(EXIT_FAILURE);
	}
	read_size = read(STDIN_FILENO, buf, count);
	if (read_size < 0)
		perror(argv[0]);
	/*allocate memory for copied*/
	/* a loop to copy input from read */
	copied = malloc(sizeof(char) * read_size);
	if (copied == NULL)
	{
		free(copied);
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < read_size - 1; i++)
	{
		copied[i] = buf[i];
	}
	arg[0] = strtok(copied, delim);
	token = 0;
	while (arg[token])
	{
		token++;
		arg[token] = strtok(NULL, delim);
	}
	
	exec_exe(arg[0], arg, NULL);
	free(buf);
	free(copied);
	return (read_size);
}
