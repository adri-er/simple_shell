#include "header.h"

void execute_no_fork(char *command_ar[], char **envp)
{
    if (execve(command_ar[0], command_ar, envp) == FILE_ERROR)
    {
	    perror("Error");
	    exit(EXIT_FAILURE);
    }
}

void execute_fork(char *command_ar[], char **envp)
{
    pid_t child;

    child = fork();
	if (child == FILE_ERROR)
    {
		perror("Error");
		return;
	}
	if (child == CHILD_PID)
	{
		execute_no_fork(command_ar, envp);
	}
    if (child > CHILD_PID)
    {
        wait(NULL);
        kill(child, SIGKILL);
    }
}

int validate_execute(char *command_array[], char **envp, int argc)
{
	char *command;
	char command_copy[BUFFER_SIZE];

	command = command_array[0];
	if (*command != '/' || (*command != '.' && command[1] != '/'))
	{
		/* is built-in? */
		/* if command is built-in execute a function and continue*/
		if (is_built_in(command))
		{
			return (IS_BUILT_IN);
		}

		_str_copy((char *)command_copy, command);

		/* iterate PATH to find executable file with (strtok) */
		/* check if exist file (F_OK) and if can execute(X_OK) */
		if (_which((char *)command_copy, envp))
		{
			/* ls -l 		  = /bin/ls */
			command_array[0] = (char *)command_copy;
		}
		else
		{
			_str_concat(command, MSG_NOT_FOUND);
			write(STDOUT_FILENO, command, strlen(command));
			return (EXIT_FAILURE);
		}
	}
	if (argc > 1)
	{
		execute_no_fork(command_array, envp);	
	}
	else
	{
		execute_fork(command_array, envp);
	}
	return (EXIT_SUCCESS);
}