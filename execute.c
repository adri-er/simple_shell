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
void _execute_fork(char *command_ar[], char **envp)
{
	pid_t child;

	child = fork();
	if (child == FILE_ERROR)
	{
		perror("");
		return;
	}
	if (child == CHILD_PID)
	{
		_execute_no_fork(command_ar, envp);
	}
	if (child > CHILD_PID)
	{
		wait(NULL);
		kill(child, SIGKILL);
	}
}
/**
 * _validate_execute - Validate case, interactive or not,
 * and execute depending the case.
 * @command_array: Array of commands introduced in terminal.
 * @envp: Array of environment variables.
 * @argc: Number of arguments in terminal.
 * @argv: Main program arguments.
 * @counter: Number of arguments in terminal.
 * Return: 1 (Success) or 0 (Failure) and 2 (Built-in).
 */
int _validate_execute(char *command_array[], char **envp,
					  char **argv, int argc, int counter)
{
	char *command;
	char command_copy[BUFFER_SIZE];
	char filename[BUFFER_SIZE];

	command = command_array[0];
	if (!_is_path(command))
	{
		if (_is_built_in(command, envp))
		{
			return (IS_BUILT_IN);
		}
		_str_copy((char *)command_copy, command);
		if (_which((char *)command_copy, envp))
		{
			command_array[0] = (char *)command_copy;
		}
		else
		{
			/*
			write(STDERR_FILENO, argv[0], _str_len(argv[0]));
			write(STDERR_FILENO, ": No such file or directory\n", 29);
			counter = counter;
			*/
			_print_error(filename, argv, command, counter);
			return (EXIT_FAILURE);
		}
	}
	if (argc > 1)
	{
		_execute_no_fork(command_array, envp);
	}
	else
	{
		_execute_fork(command_array, envp);
	}
	return (EXIT_SUCCESS);
}
