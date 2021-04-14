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
 * Return: EXIT_SUCCESS if valid, EXIT_FAILURE instead.
 */
int _process_input(char *buf_get_line, char *command_ar[])
{
	ssize_t n_characters;
	size_t length = 0;
	char *buffer_tmp = NULL;
	char *token = NULL;
	ssize_t i;

	n_characters = getline(&buffer_tmp, &length, stdin);
	if (n_characters == FILE_ERROR)
	{
		return (EOF);
	}
	if (n_characters == 1)
	{
		free(buffer_tmp);
		return (EXIT_FAILURE);
	}
	for (i = 0; i < n_characters; i++)
	{
		buf_get_line[i] = buffer_tmp[i];
	}
	free(buffer_tmp);
	buf_get_line[i - 1] = '\0';
	for (i = 0; 1; i++)
	{
		token = strtok(((i == 0) ? buf_get_line : NULL), DELIM);
		command_ar[i] = token;
		if (token == NULL)
		{
			break;
		}
	}
	return (EXIT_SUCCESS);
}
