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

void itoa(int number, char *text)
{
	size_t len_num, len_str, tmp;
	tmp = number;
	char c;

	len_str = _str_len(text);
	for (len_num = 0; tmp; len_num++)
	{
		c += '0';
		text[len_str++] = tmp + '0';
		tmp = tmp / 10;
	}
	text[len_str] = '\0';
}
