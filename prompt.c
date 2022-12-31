#include "shell.h"

/**
 * print_prompt - print command prompt
 * @status: determin which prompt to print
 * Return: void
 */

int print_prompt(int status)
{
	while (isatty(STDIN_FILENO))
	{
		if (status == 1)
		{
			write(STDOUT_FILENO, "$", 2);
			return (0);
		}
		else if (status == 2)
			write(STDOUT_FILENO, "\n$", 3);
		else
			write(STDOUT_FILENO, "\n", 2);
	}

}
