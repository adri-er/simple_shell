#include "header.h"

/**
 * main - Checks if its pipe case or not and executes corresponding case.
 * @argc: interger, number of parameters.
 * @argv: pointer to array of pointers of strings (arguments).
 * @envp: pointer to array of pointers of strings (environment variables).
 * Return: 0 on SUCCESS.
 */
int main(int argc, char **argv, char **envp)
{
	char buf_get_line[BUFFER_SIZE];
	char *command_array[BUFFER_SIZE];
	int ok = 0, check_tty = 0, counter = 0;

	check_tty = isatty(STDIN_FILENO);

	if (argc > 1)
	{
		argv++;
		_validate_execute((char **)command_array, envp, argv, argc, counter);
		return (EXIT_SUCCESS);
	}
	signal(SIGINT, exit);

	while (ok != EOF)
	{
		counter++;
		if (check_tty)
		{
			_display_prompt();
		}
		ok = _process_input(buf_get_line, command_array);
		if (ok == EXIT_FAILURE || ok == EOF)
		{
			continue;
		}
		_validate_execute((char **)command_array, envp, argv, argc, counter);
	}
	return (EXIT_SUCCESS);
}
