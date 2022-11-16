#include "main.h"

/**
 * main - Entry point for shell project.
 * @ac: Number of arguments.
 * @argv: Array of argument string.
 * Return: 0 on success, otherwise, -1.
 */

int main(__attribute__((unused)) int ac, char **argv)
{
	char *s = "($) ", *line_cpy, *line_ptr, *line;
	int count, num, ret;/* ret - return value for fork */
	ssize_t ret_bytes;
	size_t n = 1;
	char **arg = NULL;

	while (1) /* infinite loop to run terminal */
	{
		prompt(s);
		line_ptr = malloc(sizeof(char) * n);
		ret_bytes = read_command(line_ptr, n);

		num = leave_prog(line_ptr); /* chck if user wants to exit */
		if (ret_bytes == -1 || num == 0)
		{ /* if the user wants to exit */
			free(line_ptr);
			return (-1);
		}

		rem_newline(line_ptr); /* remove newline character */
		line_cpy = malloc(sizeof(char) * ret_bytes);
		line = _strcpy(line_cpy, line_ptr);
		if (line == NULL)
			break; /* get no. of tokens in array */
		count = get_token(arg, line_ptr);
		arg = malloc(sizeof(char *) * count); /* memory for string pointer */
		if (arg == NULL)
			return (-1);
		copy_string(arg, line_cpy); /* copy strings into arg */
		ret = fork_child(argv, arg); /* fork and execute */
		if (ret == -1)
			break;
	}
	free(arg);
	free(line_cpy);
	free(line_ptr);
	return (0);
}
