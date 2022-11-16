#include "main.h"

/**
 * copy_string - This  copies each string into the array.
 * @arg: Array of string arguments.
 * @line_cpy: String to be copied.
 * Return: Void.
 */

void copy_string(char **arg, char *line_cpy)
{
	int count;
	char *token;
	char *delimiter = " ";

	token = strtok(line_cpy, delimiter);

	for (count = 0; token != NULL; count++)
	{
		arg[count] = token;

		token = strtok(NULL, delimiter);
	}
	arg[count] = NULL;
}
