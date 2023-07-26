#include "headers.h"

/**
 * handle_builtin - handles builtin commands
 * @arr_tok: array of tokens
 *
 * Return: value of the builtin command, OR 0 if failure
 */
int handle_builtin(char **arr_tok)
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
	{
		if (strcmp(arr_tok[0],
			   builtins[builtin_index].name) == 0)
			return (builtins[builtin_index].function(arr_tok));
	}
	return (0);
}
