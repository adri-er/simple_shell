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
	char buf_get_line[2048];
	char *command_ar[2048];
	int ok;

	(void)argc;
    (void)argv;
	(void)envp;

	if (isatty(STDIN_FILENO))
	{
		printf( "stdin is a terminal\n" );
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
			while (1)
			{
				display_prompt();
				ok = process_input(buf_get_line, command_ar);
				if (ok == EXIT_FAILURE)
				{
					continue;
				}
				/* Check if path is introduced */
				/* CONVERT INTO MACROS */
				if (*command_ar[0] == '/' || (*command_ar[0] == '.' && (*command_ar)[1] == '/'))
				{
					execute_fork(command_ar, envp);
				}
				else
				{
					//Look for path
					//exec_fork
				}
			}
		}
	}
	else
	{
		printf("stdin is a file or a pipe\n");
	}
	return (0);
}
