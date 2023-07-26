#include "headers.h"

/**
 * _getenv - gets the value of an environment variable
 * @name: name of the environment variable to get
 *
 * Return: pointer to the value of the environment variable, or NULL
 */
char *_getenv(const char *name)
{
	unsigned int env_id, envar_length;
	char *env_var;
	char *envv_cpy;

	for (env_id = 0; __environ[env_id]; env_id++)
	{
		if (strncmp(__environ[env_id], name, strlen(name)) == 0)
		{
			envar_length = strlen(__environ[env_id]) - (strlen(name));
			env_var = malloc(sizeof(char) * envar_length);
			if (env_var == NULL)
			{
				perror("_getenv() Error: env_var malloc failed");
				return (NULL);
			}
			malloc_char(&envv_cpy, strlen(__environ[env_id]) + 1, "geten malloc error");
			strcpy(envv_cpy, __environ[env_id]);
			strncpy(env_var, envv_cpy += (strlen(name) + 1), envar_length);
			free(envv_cpy -= (strlen(name) + 1));
			return (env_var);
		}
	}
	return (NULL);
}
