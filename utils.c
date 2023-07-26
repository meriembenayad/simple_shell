#include "headers.h"

/**
 * malloc_char - allocates memory for a string
 * @string: pointer to the string to be allocated
 * @size_mall: the number of characters to allocate
 * @error_msg: the error message to be printed if malloc fails
 *
 * Return: pointer to the allocated memory, or NULL if malloc fails
 */
char *malloc_char(char **string, size_t size_mall, char *error_msg)
{
	*string = (char *)malloc(sizeof(char) * size_mall);
	if (string == NULL)
	{
		perror(error_msg);
		return (NULL);
	}
	return (*string);
}

/**
 * malloc_array - allocates memory for an arr of pointers
 * @arr: the arr to be allocated
 * @size_mall: the number of elements to allocate
 * @error_msg: the error message to be printed if malloc fails
 *
 * Return: pointer to the allocated memory, or NULL if malloc fails
 */
char **malloc_array(char **arr, size_t size_mall, char *error_msg)
{
	arr = (char **)malloc(sizeof(char *) * size_mall);
	if (arr == NULL)
	{
		perror(error_msg);
		return (NULL);
	}
	return (arr);
}

/**
 * copy_array - copies an arr of strings
 * @dest: the dest arr
 * @src: the src arr
 *
 * Return: 0 on success, -1 on error
 */
int copy_array(char **dest, char **src)
{
	size_t new_env_index, free_new_env_index;

	for (new_env_index = 0; src[new_env_index]; new_env_index++)
	{
		dest[new_env_index] = malloc(sizeof(char) * strlen(src[new_env_index]));
		if (dest[new_env_index] == NULL)
		{
			perror("_setenv() Error: new_env[new_env_index] malloc failed");
			for (free_new_env_index = 0; free_new_env_index < new_env_index;
			     free_new_env_index++)
				free(dest[new_env_index]);
			free(dest);
			return (-1);
		}
		strcpy(dest[new_env_index], src[new_env_index]);
	}
	return (0);
}

/**
 * _env_name_exists - checks if an environment variable exists
 * @name: the name of the environment variable to check
 *
 * Return: the index of the environment variable if it exists, -1 otherwise
 */
int _env_name_exists(const char *name)
{
	int env_id, is_found;

	is_found = -1;
	for (env_id = 0; __environ[env_id]; env_id++)
		if (strncmp(__environ[env_id], name, strlen(name)) == 0)
			is_found = env_id;
	return (is_found);
}

/**
 * _env_len - calculates the length of the environment

 * Return: the length of the environment
 */
int _env_len(void)
{
	unsigned int env_length;

	for (env_length = 0; __environ[env_length]; env_length++)
		;
	return (env_length);
}
