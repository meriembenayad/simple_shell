#include "headers.h"

/**
 * _exit_builtin - exits the program
 * @arr_tok: array of tokens representing the command and its arguments
 *
 * Return: exit code if no arg, otherwise the program exits with exit code
 */
int _exit_builtin(char **arr_tok)
{
	if (arr_tok[1] != NULL)
		exit(atoi(arr_tok[1]));
	else
		return (EXIT_CODE);
}
