#include "headers.h"

/**
 * free_main - free array of tokens in the main function
 * @arr_tok: array of tokens to be freed
 * @input: input string to be freed
 *
 * Return: void
 */
void free_main(char **arr_tok, char *input)
{
	int index;

	for (index = 0; arr_tok[index]; index++)
		free(arr_tok[index]);
	free(arr_tok);
	free(input);
}

/**
 * free_which - frees memory allocated for array of tokens & path variable
 * @path_var: pointer to the path variable to be freed
 * @arr_tok: array of tokens to be freed
 *
 * Return: void
 */
void free_which(char **path_var, char **arr_tok)
{
	int index;

	if (arr_tok != NULL)
	{
		for (index = 0; arr_tok[index]; index++)
			if (arr_tok[index] != NULL)
				free(arr_tok[index]);
		free(arr_tok);
	}
	if (*path_var != NULL)
		free(*path_var);
}
