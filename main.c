#include "headers.h"

/**
 * main - simple shell
 * @ac: arg
 * @arvs: arrau of args
 * @envp: environment 
 *
 * Return: return description
 */
int main(__attribute((unused)) int ac,
	 __attribute((unused)) char **arvs,
	 __attribute((unused)) char **envp)
{
	int status = 0;
	char *input, *delimiter, *which;
	size_t lineptr, cmd_num;
	char **arr_tok;

	signal(SIGINT, sigint_handler);
	input = NULL;
	lineptr = cmd_num = 0;
	delimiter = " \n";
	while (1)
	{
		cmd_num++;
		_getline(&input, &lineptr, status);
		arr_tok = _strtok(input, delimiter);
		if (!(*arr_tok))
			status = 0;
		else
		{
			if (_builtin(arr_tok))
			{
				if (handle_builtin(arr_tok) == EXIT_CODE)
				{
					free_main(arr_tok, input);
					exit(status);
				}
			}
			else
			{
				which = _which(arr_tok[0]);
				if (which != NULL)
					status = _fork(which, arr_tok);
				else
					status = error_not_found(arvs, arr_tok, cmd_num);
			}
		}
		free_main(arr_tok, input);
		input = NULL;
	}
	return (0);
}
