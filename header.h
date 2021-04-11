#ifndef HEADER_H
#define HEADER_H

#define BUFFER_PROMPT "$ "
#define LENGTH_PROMPT 2
#define DELIM " "
#define FILE_ERROR -1
#define CHILD_PID 0
#define BUFFER_SIZE 2048
#define PATH "PATH="
#define DELIM_PATH ":"
#define MSG_NOT_FOUND ": not found\n"
#define NOT_FOUND_SIZE 11
#define TRUE 1
#define FALSE 0



#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

/* Structs*/
/* TODO: document this*/
typedef struct built_in
{
	char *name;
	void (*function)(void);
} built_in_t;


/* Prototypes*/

void display_prompt(void);
int process_input(char *buf_get_line, char *command_ar[]);
void execute_no_fork(char *command_ar[], char **envp);
void execute_fork(char *command_ar[], char **envp);
int _str_cmp(char *str1, char *str2);
size_t _str_len(char *string);
int is_built_in(char *command);
char *_getenv(char *key, char *envp[]);
void _str_concat(char *str1, char *str2);
void _str_copy(char *buffer, char *text);
int _which(char *filename, char *envp[]);

/* built-ins */
void _printenv(void);
void quit(void);

#endif /* HEADER_H */
