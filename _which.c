#include "headers.h"

/**
 * valid_path - checks if filename is valid path
 * @filename: filename to check
 *
 * Return: 1 if the filename exist, 0 otherwise
 */
int valid_path(char *filename)
{
	size_t length = strlen(filename);

	if (length >= strlen("../"))
		if (strncmp(filename, "../", strlen("../")) == 0)
			return (1);
	if (length >= strlen("./"))
		if (strncmp(filename, "./", strlen("./")) == 0)
			return (1);
	if (length >= strlen("/"))
		if (strncmp(filename, "/", strlen("/")) == 0)
			return (1);
	return (0);
}

/**
 * creates_filepath - creates file path
 * @file_path: pointer to the file path to be created
 * @arr_tok: array of tokens
 * @filename: filename append to the directory path
 * @token_index: index of the directory path in the arr_tok array
 *
 * Return: void
 */
void creates_filepath(char **file_path, char **arr_tok,
		      char *filename, int token_index)
{
	malloc_char(file_path,
		    (strlen(arr_tok[token_index]) + strlen(filename) + 2),
		    "_which Error: malloc failed for file_path");
	strcpy(*file_path, arr_tok[token_index]);
	strcat(*file_path, "/");
	strcat(*file_path, filename);
	strcat(*file_path, "\0");
}

/**
 * _which - searches for location of a command
 * @filename: name of the command to search for
 *
 * Return: pointer to the path of the command, or NULL
 */
char *_which(char *filename)
{
	struct stat sb;
	char *path_var, *delimiter, *file_path;
	char **arr_tok;
	int token_index, file_path_exist;

	delimiter = ":";
	path_var = _getenv("PATH");
	if (path_var != NULL)
	{
		arr_tok = _strtok(path_var, delimiter);
		if (arr_tok != NULL)
		{
			for (token_index = 0; arr_tok[token_index]; token_index++)
			{
				creates_filepath(&file_path, arr_tok, filename, token_index);
				file_path_exist = stat(file_path, &sb);
				if (file_path_exist == 0)
				{
					free_which(&path_var, arr_tok);
					return (file_path);
				}
				free(file_path);
			}
			free_which(&path_var, arr_tok);
		}
		else
			free(path_var);
	}
	file_path_exist = stat(filename, &sb);
	if (file_path_exist == 0 && valid_path(filename))
		return (strdup(filename));
	return (NULL);
}
