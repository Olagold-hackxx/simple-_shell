#include "shell.h"

/**
 *
 *
 */

char *init_mem(char *arg, size_t mem_len)
{
	size_t i;

	for (i = 0; i < mem_len; i++)
		arg[i] = 0;
	return (arg);
}

/**
 *
 *
 */

char **ptr_malloc(size_t mem_len)
{
	char **mem;

	mem = malloc(sizeof(char *) * mem_len);
	if (mem == NULL)
	{
		exit(EXIT_FAILURE);
	}
	return (mem);
}

/**
 * 
 * 
 */

char *chr_malloc(size_t mem_len)
{
	char *mem;

	mem = malloc(sizeof(char) * mem_len);
	if (mem == NULL)
	{
		exit(EXIT_FAILURE);
	}
	return (mem);
}

