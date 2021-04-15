#include "header.h"

/**
* _printenv - print environment.
* @envp: environment variables array.
*
* Return: None.
*/
void _printenv(char **envp)
{
	size_t i, length;

	if (envp == NULL)
	{
		return;
	}

	for (i = 0; envp[i] != NULL; i++)
	{
		length = _str_len(envp[i]);

		if (write(STDOUT_FILENO, envp[i], length) == -1)
		{
			perror("Error");
			return;
		}

		if (write(STDOUT_FILENO, "\n", 1) == -1)
		{
			perror("Error");
			return;
		}
	}
}

/**
 * _quit - Exit the simple shell.
 * @envp: Environment variables array.
 *
 * Return: None.
 */
void _quit(char **envp)
{
	envp = envp;
	exit(EXIT_SUCCESS);
}

/**
*  _is_built_in - receive pointer nd searches for related function.
*	@command: Command which is going to relate to a function.
*	@envp: Array of environment variables.
*
*	Return: True if there is a related function, False instead.
*/
int _is_built_in(char *command, char **envp)
{
	size_t i;

	built_in_t list[] = {
		{"env", _printenv},
		{"exit", _quit},
		{NULL, NULL}};

	for (i = 0; list[i].name != NULL; i++)
	{
		if (_str_cmp(command, list[i].name))
		{
			list[i].function(envp);
			return (TRUE);
		}
	}
	return (FALSE);
}
