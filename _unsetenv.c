#include "headers.h"

/**
 * _unsetenv - removes an environment variable
 * @name: the name of the environment variable to be removed
 *
 * Return: 0 on success, -1 on error
 */
int _unsetenv(const char *name)
{
	unsigned int env_id;
	int new_env_index, free_new_env_index, found_index;
	char **new_env;

	new_env = NULL;
	env_id = _env_len();
	found_index = _env_name_exists(name);
	if (found_index != -1)
	{
		new_env = malloc_array(new_env, env_id, "_unsetenv() Error: malloc failed");
		for (new_env_index = 0; __environ[new_env_index]; new_env_index++)
		{
			if (new_env_index != found_index)
			{
				new_env[new_env_index] = malloc(sizeof(char) *
								strlen(__environ[new_env_index]));
				if (new_env[new_env_index] == NULL)
				{
					perror("_unsetenv() Error: new_env[new_env_index] malloc failed");
					for (free_new_env_index = 0; free_new_env_index < new_env_index;
					     free_new_env_index++)
						free(new_env[new_env_index]);
					free(new_env);
					return (-1);
				}
				strcpy(new_env[new_env_index], __environ[new_env_index]);
			}
		}
		new_env[env_id] = NULL;
		__environ = new_env;
	}
	return (0);
}
