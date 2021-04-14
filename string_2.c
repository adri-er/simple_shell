#include "header.h"

/**
 * _str_copy - Copy a string to a buffer.
 * @buffer: buffer in which string is copied.
 * @text: text to copy in the buffer.
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

/**
 * _itoa - transform number to string
 * @number: int number
 * @text: char result transform number
 * Return: None
 */
void _itoa(int number, char *text)
{
	size_t len_num, len_str, tmp;
	char c;

	tmp = number;
	len_str = _str_len(text);

	for (len_num = 0; tmp; len_num++)
	{
		c += '0';
		text[len_str++] = tmp + '0';
		tmp = tmp / 10;
	}
	text[len_str] = '\0';
}
/**
 * _print_error - manage error message
 * @filename: char
 * @argv: char
 * @command: char
 * @counter: int
 */
void _print_error(char *filename, char **argv, char *command, int counter)
{
	_str_copy((char *)filename, argv[0]);
	_str_concat(filename, ERROR_SEPARATOR);

	_itoa(counter, filename);
	_str_concat(filename, ERROR_SEPARATOR);

	_str_concat(filename, command);
	_str_concat(filename, ERROR_SEPARATOR);

	_str_concat(filename, MSG_NOT_FOUND);
	write(STDERR_FILENO, filename, _str_len(filename));
}
