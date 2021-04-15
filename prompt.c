#include "header.h"

/**
 * _display_prompt - prints prompt specified by buffer "$ ".
 * Return: None.
 */
void _display_prompt(void)
{
	ssize_t ch;

	ch = write(STDOUT_FILENO, BUFFER_PROMPT, LENGTH_PROMPT);
	if (ch == -1)
	{
		exit(EXIT_FAILURE);
	}
}

/**
 * _process_input - function that receives an entry of user (stdin)
 * and copy entry in buf_get_line
 * @buf_get_line: pointer to pointer to char buffer in main.
 * @command_ar: array of commands introduced.
 * @argv: array of Arguments.
 * @counter: counter of number or commands attempt to executed.
 * Return: EXIT_SUCCESS if valid, EXIT_FAILURE instead.
 */
int _process_input(char *buf_get_line, char *command_ar[],
				   char *argv[], int counter)
{
	ssize_t n_characters = 0, i = 0, j = 0, double_spaces = 0;
	size_t length = 0;
	char *buffer_tmp = NULL, *token = NULL;

	n_characters = getline(&buffer_tmp, &length, stdin);
	if (n_characters == FILE_ERROR)
	{
		free(buffer_tmp);
		return (EOF);
	}
	if (n_characters == 1)
	{
		free(buffer_tmp);
		return (EXIT_FAILURE);
	}
	for (i = 0, j = 0; i < n_characters; i++)
	{
		if (buffer_tmp[i] != ' ')
			double_spaces = 1;
		if (double_spaces)
		{
			buf_get_line[j] = buffer_tmp[i];
			j++;
		}
	}
	free(buffer_tmp);

	if (j == 1)
		return (EXIT_FAILURE);

	buf_get_line[j - 1] = '\0';

	for (i = 0; 1; i++)
	{
		token = strtok(((i == 0) ? buf_get_line : NULL), DELIM);
		command_ar[i] = token;
		if (token == NULL)
			break;
		if (i == 0 && _str_len(token) > FILENAME_LIMIT_SIZE)
		{
			_print_error(argv[0], argv, token, counter);
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}
