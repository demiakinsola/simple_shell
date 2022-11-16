#include "main.h"

/**
 * get_token - This tokenizes a string and returns the number of strings.
 * @arg: Array of string arguments.
 * @line_ptr: String to tokenize.
 *
 * Return: Number of strings.
 */

int get_token(char **arg, char *line_ptr)
{

	int count;
	char *token, *delimiter;

	delimiter = " ";
	count = 0;

	(void) arg;

	token = strtok(line_ptr, delimiter);
	while (token != NULL)
	{
		count++;
		token = strtok(NULL, delimiter);
	}
	count++;
	return (count);
}

