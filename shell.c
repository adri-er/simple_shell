#include "header.h"

/**
 * main -
 * @argc: interger, number of parameters
 * @argv: pointer to array of pointers of strings (arguments)
 * @envp: pointer to array of pointers of strings (environment variables)
 * Return: 0 on SUCCESS
 */

int main(int argc, char **argv, char **envp)
{
	char buf_get_line[BUFFER_SIZE];
	char *command_array[BUFFER_SIZE];
	int ok = 0, check_tty = 0;

	check_tty = isatty(STDIN_FILENO);

	if (argc > 1)
	{
		/*argc in NO INTERACTIVE mode*/
		argv++;
		validate_execute(argv, envp, argc);
		return (EXIT_SUCCESS);
	}
	/*argc in INTERACTIVE mode*/
	/*Signal that receives Ctr+C*/
	signal(SIGINT, exit);
	/*sleep(60);*/

	while (ok != EOF)
	{
		if (check_tty)
		{
			display_prompt();
		}
		ok = process_input(buf_get_line, command_array);
		if (ok == EXIT_FAILURE || ok == EOF)
		{
			continue;
		}
		validate_execute(command_array, envp, argc);
	}
	return (EXIT_SUCCESS);
}
