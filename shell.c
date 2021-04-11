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
	char *command_ar[BUFFER_SIZE];
	char *command;
	char command_copy[BUFFER_SIZE];
	int ok;

	(void)argc;
	(void)argv;
	(void)envp;

	if (isatty(STDIN_FILENO))
	{
		printf("stdin is a terminal\n");
		if (argc > 1)
		{
			/*argc in NO INTERACTIVE mode*/
		}
		else
		{
			/*argc in INTERACTIVE mode*/
			/*Signal that receives Ctr+C*/
			signal(SIGINT, exit);
			/*sleep(60);*/

			while (TRUE)
			{
				display_prompt();
				ok = process_input(buf_get_line, command_ar);
				if (ok == EXIT_FAILURE)
				{
					continue;
				}

				command = command_ar[0];
				/* Check if path is introduced */
				if (*command == '/' || (*command == '.' && command[1] == '/'))
				{
					execute_fork(command_ar, envp);
				}
				else
				{
					/* is built-in? */
					/* if command is built-in execute a function and
						continue
					*/
					if (is_built_in(command))
					{
						continue;
					}

					_str_copy((char *)command_copy, command);

					/* iterate PATH to find executable file with (strtok) */
					/* check if exist file (F_OK) and if can execute(X_OK) */
					if (_which((char *)command_copy, envp))
					{
						/* ls -l 		  = /bin/ls */
						command_ar[0] = (char *)command_copy;
						execute_fork(command_ar, envp);
					}
					else
					{
						_str_concat(command, MSG_NOT_FOUND);
						write(STDOUT_FILENO, command, strlen(command));
					}
				}
			}
		}
	}
	else
	{
		printf("stdin is a file or a pipe\n");
	}
	return (EXIT_SUCCESS);
}
