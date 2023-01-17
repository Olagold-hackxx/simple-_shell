#include "shell.h"

/**
 * exec_exe - execute externals(executable)
 * @path: Path to exec
 * @arg: cmd args
 * @envp: environ variables
 * Return: 0 on success
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

/**
 * 
 * 
 * 
 */
void execute(char *buf)
{
	char **arg, *token, *path, *delim = " ", **envp = NULL;
	ssize_t path_len = 0;
	int i;

	arg = ptr_malloc(20);

	token = strtok(buf, delim);
	i = 0;
	arg[0] = token;
	/* get len of first token which is also the path*/
	path_len = strtok_len(buf, arg[0], i);
	path = chr_malloc(path_len + 1);
	init_mem(path, path_len);

	while (arg[i])
	{
		i++;
		arg[i] = strtok(NULL, delim);
	}
	strncpy(path, buf, path_len);
	path[path_len] = '\0';
	exec_exe(path, arg, envp);
	free(buf);
	free(path);
	free(arg);
}
	