#include "headers.h"

/**
 * create_envar - creates a new environment variable
 * @env_var: pointer to the environment variable to be created
 * @envar_length: length of the environment variable
 * @name: name of the environment variable
 * @value: value of the environment variable
 *
 * Return: return description
 */
void create_envar(char **env_var, unsigned int envar_length, const char *name,
		  const char *value)
{
	*env_var = malloc_char(env_var, envar_length,
			       "_setenv() Error: env_var malloc failed");
	envar_length = strlen(name) + strlen(value) + 2;
	*env_var = malloc_char(env_var, envar_length,
			       "_setenv() Error: env_var malloc failed");
	strcpy(*env_var, name);
	strcat(*env_var, "=");
	strcat(*env_var, value);
	strcat(*env_var, "\0");
}

/**
 * _env_set_exists - sets the value of an existing environment variable
 * @env_var: environment variable to be set
 * @envar_length: length of the environment variable
 * @name: name of the environment variable
 * @overwrite: value of the environment variable if it already exists
 *
 * Return: 0 on success, -1 on error
 */
int _env_set_exists(char *env_var, unsigned int envar_length, const char *name,
		    int overwrite)
{
	unsigned int env_id;

	for (env_id = 0; __environ[env_id]; env_id++)
	{
		if (strncmp(__environ[env_id], name, strlen(name)) == 0 && overwrite != 0)
		{
			free(__environ[env_id]);
			__environ[env_id] = malloc(sizeof(char) * envar_length);
			if (__environ[env_id] == NULL)
			{
				perror("_setenv() Error: __environ[env_id] malloc failed");
				free(env_var);
				return (-1);
			}
			strcpy(__environ[env_id], env_var);
			free(env_var);
			return (0);
		}
	}
	return (0);
}

/**
 * env_not_exists - creates new environment variable if it doesn't exist
 * @env_var: environment variable to be created
 * @envar_length: length of the environment variable
 * @env_length: length of enviroment
 *
 * Return: 0 on success, -1 on error
 */
int env_not_exists(char *env_var, unsigned int envar_length,
		   unsigned int env_length)
{
	unsigned int free_new_env_index;
	char **new_env;

	new_env = (char **)malloc(sizeof(char *) * (env_length + 2));
	if (new_env == NULL)
	{
		perror("_setenv() Error: new_env malloc failed");
		free(env_var);
		return (-1);
	}
	copy_array(new_env, __environ);
	new_env[env_length] = malloc(sizeof(char) * envar_length);
	if (new_env[env_length] == NULL)
	{
		perror("_setenv() Error: new_env[env_id] malloc failed");
		for (free_new_env_index = 0; free_new_env_index < env_length;
		     free_new_env_index++)
			free(new_env[free_new_env_index]);
		free(new_env);
		free(env_var);
		return (-1);
	}
	strcpy(new_env[env_length], env_var);
	new_env[env_length + 1] = NULL;
	free(env_var);
	__environ = new_env;
	return (0);
}

/**
 * _setenv - sets the value of an environment variable
 * @name: name of the environment variable to set
 * @value: value to set the environment variable
 * @overwrite: value of the environment variable if it already exists
 *
 * Return: 0 on success
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	unsigned int envar_length;
	char *env_var;

	envar_length = strlen(name) + strlen(value) + 2;
	create_envar(&env_var, envar_length, name, value);
	_env_set_exists(env_var, envar_length, name, overwrite);
	if (_env_name_exists(name) != -1)
		_env_set_exists(env_var, envar_length, name, overwrite);
	else
		env_not_exists(env_var, envar_length, _env_len());
	return (0);
}
