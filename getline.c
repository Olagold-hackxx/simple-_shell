#include "shell.h"

/**
 * _getline - get input from stdin in interactive mode
 * format input
 * @argv: ptr to ptr holding progam name
 * Return: read size
 */

size_t _getline(char **argv)
{
	char *buf = NULL, *copied;
	size_t buf_size = 100;
	ssize_t read_size;

	/*read user input from stdin */
	read_size = getline(&buf, &buf_size, stdin);
	if (read_size < 0)
		perror(argv[0]);

	copied = chr_malloc(read_size);

	init_mem(copied, read_size);
	/*copy input from getline */
	_strncat(copied, buf, read_size - 1);
	copied[read_size - 1] = '\0';
	free(buf);
	copied = strformat(copied, read_size);

	execute(copied);
	return (read_size);
}

/**
 * readline - read from terminal in non interactive mode
 * @argv: ptr to ptr holding progam name
 * Return: read size
 */

size_t readline(char **argv)
{
	size_t count = 100;
	char *buf, *copied;
	ssize_t read_size;

	/*alloc memory for buf*/
	buf = chr_malloc(count);
	init_mem(buf, count);

	read_size = read(STDIN_FILENO, buf, count);
	if (read_size < 0)
		perror(argv[0]);

	copied = chr_malloc(read_size);
	init_mem(copied, read_size);
	_strncat(copied, buf, read_size);
	free(buf);
	copied = strformat(copied, read_size);
	execute(copied);
	return (read_size);
}
