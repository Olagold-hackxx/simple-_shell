#include "shell.h"

/**
 * print_prompt - print command prompt
 * @status: determine which prompt to print
 * Return: void
 */

int print_prompt(int status)
{
	if (status == 1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		return (0);
	}
	else
	{
		write(STDOUT_FILENO, "$ ", 2);
		return (0);
	}
}
