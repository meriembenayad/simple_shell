#include "headers.h"

/**
 * prompt - Display prompt of simple shell
 * Return: void
 */
void prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", strlen("$ "));
}
