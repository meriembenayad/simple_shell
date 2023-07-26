#include "headers.h"

/**
 * split_cmd - Splits command string into an arr of args
 * @input: input string
 * @delimiter: delimiter string
 *
 * Return: -1 if failure and a number if not
 */
size_t split_cmd(char *input, char *delimiter)
{
	char *token;
	size_t token_cnt;

	token_cnt = 0;
	token = strtok(input, delimiter);
	while (token != NULL)
	{
		token_cnt++;
		token = strtok(NULL, delimiter);
	}
	return (token_cnt);
}
/**
 * _strtok - Splits string into an arr of words
 * @input: input string
 * @delimiter: delimiter string
 *
 * Return: returns NULL on failure and the arr on success
 */
char **_strtok(char *input, char *delimiter)
{
	char *input_cpy, *token;
	char **arr_tok;
	size_t token_cnt, token_index, token_free_index;

	arr_tok = NULL;
	malloc_char(&input_cpy, strlen(input) + 1, "strtok Error: malloc failure");
	strcpy(input_cpy, input);
	token_cnt = split_cmd(input_cpy, delimiter);
	arr_tok = malloc_array(arr_tok, token_cnt + 1, "strtok Error: malloc fails");
	strcpy(input_cpy, input);
	token = strtok(input_cpy, delimiter);
	for (token_index = 0; token_index < token_cnt; token_index++)
	{
		arr_tok[token_index] = (char *)malloc(sizeof(char) * strlen(token) + 1);
		if (arr_tok[token_index] == NULL)
		{
			for (token_free_index = 0;
			     token_free_index < token_index;
			     token_free_index++)
				free(arr_tok[token_free_index]);
			free(input_cpy);
			free(arr_tok);
			perror("strtok Error: arr_tok malloc failure");
			return (NULL);
		}
		strcpy(arr_tok[token_index], token);
		token = strtok(NULL, delimiter);
	}
	free(input_cpy);
	arr_tok[token_cnt] = NULL;
	return (arr_tok);
}
