#include "main.h"

/**
 * prompt - This displays the prompt.
 * @s: Prompt to be displayed.
 *
 * Return: Void.
 */

void prompt(char *s)
{
	int index;
	int count = 2;

	for (index = 0; index < count; index++)
		_putchar(s[index]);
}
