#include "headers.h"

/**
 * error_not_found - prints error msg if command not found
 * @arvs: array of argv passed
 * @arr_tok: array of tokens string
 * @cmd_num: counter cmd
 *
 * Return: 127 cmd not found
 */
int error_not_found(char **arvs, char **arr_tok, size_t cmd_num)
{
	char *error_str;
	char *cmd_num_str = _itoa(cmd_num);
	int size = (strlen(arvs[0]) + (2 * strlen(": ")) +
		    digit_counter(cmd_num) + strlen(arr_tok[0]) +
		    strlen(": not found\n") + 1);

	malloc_char(&error_str, size, "error_not_found Error: malloc error");
	strcpy(error_str, arvs[0]);
	strcat(error_str, ": ");
	strcat(error_str, cmd_num_str);
	strcat(error_str, ": ");
	strcat(error_str, arr_tok[0]);
	strcat(error_str, ": not found\n");
	strcat(error_str, "\0");

	write(STDERR_FILENO, error_str, strlen(error_str));
	free(error_str);
	free(cmd_num_str);
	return (127);
}
