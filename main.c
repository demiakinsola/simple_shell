#include "main.h"

/**
 * Main - Entry point for shell project.
 * Return: 0 on success, otherwise, -1.
 */

int main(__attribute__((unused)) int ac, char **argv)
{
	char *s = "$ ", *line_cpy, *delimiter = " ", *token;
	int count, index;
	ssize_t ret_bytes;
	char *line_ptr, *line;// *line_cpy, *line;
	size_t n = 1;
	pid_t pid;
	char **arg = NULL;
	int ret;

	while(1) /* infinite loop to run terminal */
	{
		prompt(s);
		line_ptr = malloc(sizeof(char) * n);
		ret_bytes = read_command(line_ptr, n);
		if (ret_bytes == -1) /* if user presses Ctrl D/C */
		{
			free(line_ptr);
			return (-1);
		}
		rem_newline(line_ptr); /* remove newline character */
		line_cpy = malloc(sizeof(char) * ret_bytes);
		line = _strcpy(line_cpy, line_ptr, ret_bytes);

		count = get_token(arg, line_ptr);
		arg = malloc(sizeof(char *) * count); /* memory for string pointer */
		if (arg == NULL)
			return (-1);
		copy_string(arg, line_cpy);
		if ((ret = fork_child(argv, arg)) == -1)
			break;
	}
	free(arg);
	free(line_cpy);
	free(line_ptr);
	return (0);
}
