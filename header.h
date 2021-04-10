#ifndef HEADER_H
#define HEADER_H

#define BUFFER_PROMPT "$ "
#define LENGTH_PROMPT 2
#define DELIM " "
#define FILE_ERROR -1

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

void display_prompt(void);
int process_input(char *buf_get_line, char **command_ar[]);


#endif /* HEADER_H */
