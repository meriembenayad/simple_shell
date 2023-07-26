#include "headers.h"

/**
 * rev_string - reverses a string
 * @str: the string
 *
 * Return: void
 */
void rev_string(char *str)
{
	int i, len;
	char tmp;

	len = 0;
	while (str[len] != '\0')
		len++;
	len--;
	for (i = 0; i < len; i++, len--)
	{
		tmp = str[i];
		str[i] = str[len];
		str[len] = tmp;
	}
}

/**
 * _itoa - converts int to string
 * @cmd_num: number to be converted
 *
 * Return: string
 */
char *_itoa(size_t cmd_num)
{
	char *str = malloc(sizeof(char) * (32 + 1));
	int i = 0;

	while (cmd_num > 0)
	{
		str[i++] = cmd_num % 10 + '0';
		cmd_num /= 10;
	}
	str[i] = '\0';
	rev_string(str);

	return (str);
}
