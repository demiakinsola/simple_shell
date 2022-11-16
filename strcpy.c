#include "main.h"

/**
 * _strcpy - This copies a string.
 * @dest: Placeholder for copied string.
 * @src: String to be copied.
 *
 * Return: pointer to string copied.
 */

char *_strcpy(char *dest, char *src)
{
	int index;

	if (dest == NULL && src == NULL)
		return (NULL);

	for (index = 0; src[index]; index++)
	{
		dest[index] = src[index];
	}
	dest[index] = '\0';

	return (dest);
}
