#ifndef HEADER_H
#define HEADER_H

#define BUFFER_PROMPT "$ "
#define LENGTH_PROMPT 2
#define DELIM " "
#define FILE_ERROR -1
#define CHILD_PID 0

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

void display_prompt(void);
int process_input(char *buf_get_line, char *command_ar[]);
void execute_no_fork(char *command_ar[], char **envp);
void execute_fork(char *command_ar[], char **envp);

#endif /* HEADER_H */
