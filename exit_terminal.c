#include "main.h"

/**
 * leave_prog - This checks if the user enters the exit command.
 * @line_ptr: Command entered.
 * Return: 0 on success, otherwise -1.
 */

int leave_prog(char *line_ptr)
{
	char *command = "exit";
	int index = 0;

	if (line_ptr == NULL)
		return (-1);
	while (command[index] && line_ptr[index])
	{
		if (command[index] == line_ptr[index])
			index++;
		else
			return (-1);
	}

	return (0);
}
