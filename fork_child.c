#include "main.h"

/**
 * fork_child - This creates a child process and executes a program.
 * @arg: Array of string arguments.
 * @argv: Argument to main.
 *
 * Return: 0 on success, otherwise -1.
 */

int fork_child(char **argv, char **arg)
{
	pid_t pid; /* child process */
	int status;

	if (access(arg[0], F_OK) == -1)
	{
		perror(argv[0]);
		return (0);
	}
	pid = fork();
	if (pid < 0) /* error */
		return (-1);

	if (pid == 0) /* child process */
	{
		if (execve(arg[0], arg, environ) == -1)
			perror(argv[0]);
	}

	else if (pid > 0) /* parent process */
		wait(&status);

	return (0);
}
