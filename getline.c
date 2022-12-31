#include "shell.h"

/**
 *
 *
 */

size_t _getline(char *argv[])
{
	char *buf = NULL;
	size_t buf_size = 0;
	ssize_t read_size, i;
	char *copied, *arg[20], *delim = " ";
	int token;

	read_size = getline(&buf, &buf_size, stdin);
	if (read_size < 0)
		perror(argv[0]);

	copied = malloc(sizeof(char) * read_size);
	if (copied == NULL)
		exit(EXIT_FAILURE);

	/* a loop to copy input from getline */
	for(i = 0; i < read_size-1; i++)
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
	arg[token+1] = NULL;

	exec_exe(arg[0], arg, NULL);

	return (read_size);
}
