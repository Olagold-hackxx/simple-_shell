#include "shell.h"

/**
 *
 *
 */

int exec_exe(char *path, char **arg, char **envp)
{
	int val;
	pid_t pid;

	pid = fork();
	if (pid < 0)
		perror("Fork failed");
	if (pid == 0)
	{
		val = execve(path, arg, envp);
		if (val == -1)
			perror(arg[0]);
	}
	else
		wait(NULL);
	return (0);
}
