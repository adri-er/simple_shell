#include "header.h"

extern char **environ;
/**
* _printenv - print environment
*/
void _printenv()
{
	size_t i, length;

	for (i = 0; environ[i] != NULL; i++)
	{
		length = _str_len(environ[i]);

		if (write(STDOUT_FILENO, environ[i], length) == -1)
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
 *
 */
void quit(void)
{
	exit(EXIT_SUCCESS);
}

/**
*  sele_function - receive char * and search and select by case
				  correct function
*/
int is_built_in(char *command)
{
	size_t i;

	built_in_t list[] = {
		{"env", _printenv},
		{"exit", quit},
		{NULL, NULL}};

	/* check list of built-ins */
	for (i = 0; list[i].name != NULL; i++)
	{
		if (_str_cmp(command, list[i].name))
		{
			list[i].function();
			return (TRUE);
		}
	}
	return (FALSE);
}
