#include "header.h"


/**
 * display_prompt - functions that prints prompt "$ "
 *
 * Return: (void)
 */


void display_prompt(void)
{
	ssize_t ch;

	ch = write(STDOUT_FILENO, BUFFER_PROMPT, LENGTH_PROMPT);
	/*write() guard conditions*/
	if (ch == -1)
	{
		exit(EXIT_FAILURE);
	}
}

/**
 * process_input - function that receives entry of user (stdin)
 * and copy entry in buf_get_line
 * @buffer_get_line: pointer to pointer to char buffer in main
 * Return: 1 on EXIT_SUCCESS; 0 on EXIT_FAILURE
 */

int process_input(char *buf_get_line, char *command_ar[])
{
	ssize_t n_characters;
	size_t length = 0;
	char *buffer_tmp = NULL;
	char *token = NULL;
	ssize_t i;

	/*Entry of user*/
	n_characters = getline(&buffer_tmp, &length, stdin);
	/*getline() guard conditions*/
	if (n_characters == FILE_ERROR)
	{
		perror("Error");
		return (EOF);
	}
	if (n_characters == 1)
	{
		free(buffer_tmp);
		return (EXIT_FAILURE);
	}
	/*buffer_temp copy in buffer_get_line*/
	for (i = 0; i < n_characters; i++)
	{
		buf_get_line[i] = buffer_tmp[i];
	}
	free(buffer_tmp);
	buf_get_line[i - 1] = '\0';
	/*Separates the buffer into string tokens*/
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
