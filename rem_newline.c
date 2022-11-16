#include "main.h"

/**
 * rem_newline - This removes the new line character from a string.
 * @line: The string.
 * Return: Void.
 */
void rem_newline(char *line)
{
	int index = 0;

	for ( ; line[index]; index++)
		;

	if (line[index - 1] == '\n')
		line[index - 1] = 0;
}
