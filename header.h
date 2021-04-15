#ifndef HEADER_H
#define HEADER_H

/* MACROS */
#define BUFFER_PROMPT "$ "
#define LENGTH_PROMPT 3
#define DELIM " "
#define FILE_ERROR -1
#define CHILD_PID 0
#define BUFFER_SIZE 2048
#define PATH "PATH="
#define DELIM_PATH ":"
#define FILENAME_LIMIT_SIZE 255

#define NOT_FOUND_SIZE 11
#define TRUE 1
#define FALSE 0
#define IS_BUILT_IN 1
#define ERROR_SEPARATOR ": "

/* Constants error */
#define ERR_EXEC_NO_READ 2
#define ERR_NAME_LONG 3
#define ERR_NO_EXEC 4
#define ERR_NOT_FOUND 5
#define EXIT_SH_FAILURE 127

/* Constants error */
#define MSG_ARG_MODE "Can't open "
#define MSG_NAME_LONG "File name too long\n"
#define MSG_NO_EXEC "Permission denied\n"
#define MSG_NOT_FOUND "not found\n"


/* Libraries */
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
/**
 * struct built_in_struct - Struct for a shell built-in function,
 * name of the command and pointer to related function.
 * @name: command introduced by user.
 * @function: Function to be executed.
 */
typedef struct built_in_struct
{
	char *name;
	void (*function)(char **);
} built_in_t;

/* Prototypes*/
void _display_prompt(void);
int _process_input(char *, char **, char **, int);
void _execute_no_fork(char *command_ar[], char **envp);
int _execute_fork(char *command_ar[], char **envp);
int _str_cmp(char *str1, char *str2);
size_t _str_len(char *string);
int _is_built_in(char *command, char **envp);
char *_getenv(char *key, char *envp[]);
void _str_concat(char *str1, char *str2);
void _str_copy(char *buffer, char *text);
int _which(char *filename, char *envp[]);
int _validate_execute(char **, char **, char **, int);
int _is_path(char *command);
void _itoa(int number, char *text);
int _print_error(char *filename, char **argv, char *command, int counter);

/* built-ins */
void _printenv(char **envp);
void _quit(char **envp);

#endif /* HEADER_H */
