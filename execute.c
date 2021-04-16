#include "header.h"

/**
 * _execute_no_fork - Execute on parent process.
 * @command_ar: Array of commands introduced.
 * @envp: Array of environment variables.
 * Return: None.
 */
void _execute_no_fork(char *command_ar[], char **envp)
{
	if (execve(command_ar[0], command_ar, envp) == FILE_ERROR)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
}

/**
 * _execute_fork - Execute on a child process.
 * @command_ar: Array of commands introduced.
 * @envp: Array of environment variables.
 * Return: None.
 */
int _execute_fork(char *command_ar[], char **envp)
{
	pid_t child;
	int status = 0, exit_status = 0;

	child = fork();
	if (child == FILE_ERROR)
	{
		perror("");
		return (EXIT_FAILURE);
	}
	if (child == CHILD_PID)
	{
		_execute_no_fork(command_ar, envp);
	}
	if (child > CHILD_PID)
	{
		wait(&status);
		kill(child, SIGKILL);
		exit_status = WEXITSTATUS(status);
	}
	return (exit_status);
}
/**
 * _validate_execute - Validate case, interactive or not,
 * and execute depending the case.
 * @command_array: Array of commands introduced in terminal.
 * @envp: Array of environment variables.
 * @argv: Main program arguments.
 * @counter: Number of arguments in terminal.
 * Return: 1 (Success) or 0 (Failure) and 2 (Built-in).
 */
int _validate_execute(char *command_array[], char **envp,
					  char **argv, int counter)
{
	char *command;
	char command_copy[BUFFER_SIZE];
	char filename[BUFFER_SIZE];
	int is_error = 0;

	command = command_array[0];
	if (!_is_path(command))
	{
		if (_is_built_in(command, envp))
		{
			return (EXIT_SUCCESS);
		}
		_str_copy((char *)command_copy, command);
		if (_which((char *)command_copy, envp))
		{
			command_array[0] = (char *)command_copy;
		}
	}
	is_error = _print_error(filename, argv, command_array[0], counter);
	if (is_error == 0)
		return (EXIT_FAILURE);

	return (_execute_fork(command_array, envp));
}
