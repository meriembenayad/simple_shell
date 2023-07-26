#include "headers.h"

/**
 * _getline - reads a line from stdin
 * @input: pointer to the input buffer
 * @lineptr: pointer to the size of the input buffer
 * @status: the exit status
 *
 * Return: number of characters read, -1 on failure
 */
ssize_t _getline(char **input, size_t *lineptr, int status)
{
	ssize_t num_char;

	prompt();
	num_char = getline(input, lineptr, stdin);
	if (num_char == -1)
	{
		free(*input);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", strlen("\n"));
		exit(status);
	}
	return (num_char);
}
