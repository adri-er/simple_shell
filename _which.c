#include "header.h"

/**
 * _which - finds in the path the executable file.
 * @filename: filename to find in path.
 * @envp: array of environment variables.
 *
 * Return: 0 if no path found, 1 if path found.
 */
int _which(char *filename, char *envp[])
{
	char *path, *token, path_copy[BUFFER_SIZE], token_copy[BUFFER_SIZE];
	size_t i;
	/* input: ls */
	/* obtain path */

	token = NULL;
	path = _getenv(PATH, envp);
	if (!path)
	{
		return (FALSE);
	}

	_str_copy(path_copy, path);
	/* split by :  and obtain token */
	for (i = 0; 1; i++)
	{
		token = strtok(((i == 0) ? path_copy : NULL), DELIM_PATH);
		if (token == NULL)
		{
			break;
		}

		_str_copy(token_copy, token);

		/* concatenate /bin(token) with /    */
		_str_concat(token_copy, "/");

		/* concatenate /bin/(token) with ls(filename) */
		_str_concat(token_copy, filename);
		/* validate token_copy can access to file with execute permission */

		/* if have access*/
		if (access(token_copy, F_OK | X_OK) != -1)
		{
			_str_copy(filename, token_copy);
			return (TRUE);
		}
	}
	return (FALSE);
}
