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
	char *copied, **arg, *delim = " ", **envp = NULL;
	int token;

        /*read user input from stdin */
	read_size = getline(&buf, &buf_size, stdin);
	if (read_size < 0)
		perror(argv[0]);

	arg = _malloc(20);
	arg[0] = malloc(sizeof(char) * 10);
	//init_mem(arg, 20);
	copied = malloc(sizeof(char) * read_size);
	if (copied == NULL)
	{
		free(copied);
		exit(EXIT_FAILURE);
	}

	init_mem(copied, read_size);
	/*copy input from get4line */
	strncat(copied, buf, read_size - 1);
	arg[0] = strtok(copied, delim);
	//*arg[0] = *arg[0] + '\0';
	token = 0;
	while (arg[token])
	{
		token++;
		arg[token] = strtok(NULL, delim);
	}
	path = malloc(sizeof(char) * 10);
	init_mem(path, 10);
	path = strdup(arg[0]);
	/*append NULL to arg incase no args passed to cmd*/

	exec_exe(path, arg, envp);
	free(buf);
	free(copied);
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
	
	arg[token] = NULL;
	
	exec_exe(arg[0], arg, NULL);
	free(buf);
	free(copied);
	return (read_size);
}
