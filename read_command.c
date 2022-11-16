#include "main.h"

/**
 * read_command - This reads the command entered by users.
 * @line_ptr: Buffer to store commands read.
 * @n: Size of buffer.
 *
 * Return: Ret_bytes on success, otherwise, -1.
 */

ssize_t read_command(char *line_ptr, size_t n)
{
	ssize_t ret_bytes; /* return value for getline func. */


	if (line_ptr == NULL)
		return (-1);
	ret_bytes = getline(&line_ptr, &n, stdin);
	if (ret_bytes == -1)
	{
		_putchar('\n');
		return (-1);
	}
	return (ret_bytes);
}
