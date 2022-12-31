#include "shell.h"

/**
 *
 *
 */
int main(int argc __attribute__((unused)), char **argv)
{
	do {
		print_prompt(1);
		_getline(argv);

	} while (1);
	return (0);
}
