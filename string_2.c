#include "header.h"
/**
 *
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