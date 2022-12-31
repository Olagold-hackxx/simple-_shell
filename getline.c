#include "shell.h"

/**
 *
 *
 */

size_t _getline(char *argv[])
{
	char *buf = NULL;
	size_t buf_size = 0;
	size_t read_size;
	char *copied;
	int i;

	read_size = getline(&buf, &buf_size, stdin);
	if (read_size < 0)
		perror(argv[0]);

	copied = malloc(sizeof(char) * read_size);
	if (copied == NULL)
		exit(EXIT_FAILURE);

	for(i = 0; i < read_size-1; i++)
	{
		copied[i] = buf[i];
	}
	char *arg[] = {copied, NULL};
	exec_exe(copied, arg, NULL);
	return (read_size);
}
