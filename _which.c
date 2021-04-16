#include "header.h"

/**
 * _is_path - Check if a command is a path
 * @command: string that contains the command to check.
 * Return: 1 (Success) or 0 (Failure).
 */
int _is_path(char *command)
{
	return (*command == '/' || (*command == '.' && command[1] == '/'));
}

/**
 * _which - find in the path executable file.
 * @filename: filename to find in path.
 * @envp: array of environment variables.
 *
 * Return: path concatenated with filename.
 */
int _which(char *filename, char *envp[])
{
	char *path, *token, path_copy[BUFFER_SIZE], token_copy[BUFFER_SIZE];
	size_t i;
	struct stat stat_info;

	token = NULL;
	path = _getenv(PATH, envp);
	if (!path)
	{
		return (FALSE);
	}

	_str_copy(path_copy, path);
	for (i = 0; 1; i++)
	{
		token = strtok(((i == 0) ? path_copy : NULL), DELIM_PATH);
		if (token == NULL)
		{
			break;
		}

		_str_copy(token_copy, token);
		_str_concat(token_copy, "/");
		_str_concat(token_copy, filename);

		if (stat(token_copy, &stat_info) == 0)
		{
			_str_copy(filename, token_copy);
			return (TRUE);
		}
	}
	return (FALSE);
}
