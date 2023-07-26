#include "headers.h"

/**
 * sigint_handler - writes a newline to the stdout
 * @signal: integer
 *
 * Return: void
 */
void sigint_handler(int signal)
{
	if (signal == SIGINT)
	{
		write(STDOUT_FILENO, "\n", 1);
		prompt();
		fflush(stdout);
	}
}
