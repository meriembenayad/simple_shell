#include "headers.h"

/**
 * _env_builtin - prints the environment variables
 * @arr_tok: array tokens (unused)
 *
 * Return: the number of environment variables printed
 */
int _env_builtin(__attribute((unused)) char **arr_tok)
{
	int env_idx;

	for (env_idx = 0; __environ[env_idx]; env_idx++)
	{
		write(STDOUT_FILENO, __environ[env_idx],
		      strlen(__environ[env_idx]));
		write(STDOUT_FILENO, "\n", strlen("\n"));
	}
	return (env_idx);
}
