#include "header.h"

/**
 * _str_copy - Copy a string to a buffer.
 * @buffer: buffer in which string is copied.
 * @text: text to copy in the buffer.
 *
 * Return: None.
 */
void _str_copy(char *buffer, char *text)
{
	size_t i;

	if (!buffer || !text)
	{
		return;
	}

	for (i = 0; text[i]; i++)
	{
		buffer[i] = text[i];
	}

	buffer[i] = '\0';
}
