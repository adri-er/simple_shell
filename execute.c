#include "header.h"

/**
 * execute_no_fork - Execute on parent process.
 * @command_ar: Array of commands introduced.
 * @envp: Array of environment variables.
 *
 * Return: None.
 */
void execute_no_fork(char *command_ar[], char **envp)
{
	if (execve(command_ar[0], command_ar, envp) == FILE_ERROR)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
}

/**
 * execute_fork - Execute on a child process.
 * @command_ar: Array of commands introduced.
 * @envp: Array of environment variables.
 *
 * Return: None.
 */
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

/**
 * validate_execute - Validate case, interactive or not,
 * and execute depending the case.
 * @command_array: Array of commands introduced in terminal.
 * @envp: Array of environment variables.
 * @argc: Number of arguments in terminal.
 * @counter: Number of arguments in terminal.
 * Return: 1 (Success) or 0 (Failure) and 2 (Built-in).
 */
int validate_execute(char *command_array[], char **envp, int argc, int counter)
{
	char *command;
	char command_copy[BUFFER_SIZE];

	command = command_array[0];
	if (!is_path(command))
	{
		/* is built-in? */
		/* if command is built-in execute a function and continue*/
		if (is_built_in(command, envp))
		{
			return (IS_BUILT_IN);
		}

		_str_copy((char *)command_copy, command);

		/* iterate PATH to find executable file with (strtok) */
		/* check if exist file (F_OK) and if can execute(X_OK) */
		if (_which((char *)command_copy, envp))
		{
			command_array[0] = (char *)command_copy;
		}
		else
		{
			_str_concat(command, LINE);
			itoa(counter, command);
			_str_concat(command, MSG_NOT_FOUND);
			write(STDERR_FILENO, command, strlen(command));
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
