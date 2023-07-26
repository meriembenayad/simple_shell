#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>

#include <stddef.h>

#define EXIT_CODE 1080

/**
 * struct builtin_cmd - builtin command
 * @name: pointer to char array stores name of the built-in cmd
 * @function: function pointer that points to function implements built-in cmd
 */
struct builtin_cmd
{
	char *name;
	int (*function)(char **arr_tok);
};

void prompt(void);
void sigint_handler(int signal);
ssize_t _getline(char **input, size_t *lineptr, int status);
char **_strtok(char *input, char *delimiter);
int _fork(char *command, char **arr_tok);
char *_which(char *filename);
int _print_env(void);
char *_getenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);
char *malloc_char(char **string, size_t size_mall, char *error_msg);
char **malloc_array(char **arr, size_t size_mall, char *error_msg);
int copy_array(char **dest, char **src);
int _env_name_exists(const char *name);
int _env_len(void);
void free_which(char **path_var, char **arr_tok);
void free_main(char **arr_tok, char *input);
void rev_string(char *s);
char *_itoa(size_t cmd_num);
int digit_counter(size_t cmd_num);
int error_not_found(char **arvs, char **arr_tok, size_t cmd_num);
int _builtin(char **arr_tok);
int handle_builtin(char **arr_tok);
int _exit_builtin(char **arr_tok);
int _env_builtin(char **arr_tok);

/**
 * struct listtoken_s - singly linked list
 * @token: pointer to char array stores the token
 * @token_length: integer stores the length of the toke
 * @next: pointer to the next node
 */
typedef struct listtoken_s
{
	char *token;
	int token_length;
	struct listtoken_s *next;
} listtoken_t;

size_t print_listtoken(const listtoken_t *head);
size_t listtoken_len(const listtoken_t *head);
listtoken_t *add_node_end(listtoken_t **head, char *token);
void free_listtoken(listtoken_t **head);

#endif
