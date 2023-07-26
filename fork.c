#include "headers.h"

/**
 * _fork - creates a child process and executes a command
 * @command: the command to be executed
 * @arr_tok: an arr of tokens representing the command and its arguments
 *
 * Return: 0 on success, -1 on error
 */
int _fork(char *command, char **arr_tok)
{
	pid_t pid;
	int status, is_execve_error;

	pid = fork();
	if (pid == -1)
	{
		perror("_fork() Error: fork child unable to create");
		return (-1);
	}
	if (pid == 0)
	{
		is_execve_error = execve(command, arr_tok, __environ);
		if (is_execve_error == -1)
		{
			perror("execve: ");
			return (-1);
		}
	}
	else
	{
		wait(&status);
		free(command);
		if (WIFEXITED(status))
			status = WEXITSTATUS(status);
		if (!isatty(STDIN_FILENO))
			return (status);
	}
	return (0);
}
