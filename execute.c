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