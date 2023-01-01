#include "shell.h"

/**
 *
 *
 */
int main(int argc __attribute__((unused)), char **argv)
{
	do {
		if (isatty(STDIN_FILENO))
		{
			print_prompt(1);
			_getline(argv);
		}
		else
		{
			readline(argv);
			exit(EXIT_SUCCESS);
		}

	} while (1);
	return (0);
}
