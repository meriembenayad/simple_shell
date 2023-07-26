#include "headers.h"

/**
 * _builtin - checks if a command is a builtin command
 * @arr_tok: array of tokens
 *
 * Return: 1 if success 0 if failure
 */
int _builtin(char **arr_tok)
{
	int builtin_index;
	const struct builtin_cmd builtins[] = {
	    {"env", _env_builtin},
	    {"exit", _exit_builtin},
	    {NULL, NULL}};

	if (arr_tok == NULL)
		return (0);
	if (arr_tok[0] == NULL)
		return (0);

	for (builtin_index = 0; builtins[builtin_index].name != NULL;
	     builtin_index++)
		if (strcmp(arr_tok[0],
			   builtins[builtin_index].name) == 0)
			return (1);
	return (0);
}
