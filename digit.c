#include "headers.h"

/**
 * digit_counter - counts the digit
 * @cmd_num: the number to be counted
 *
 * Return: the number of the digits
 */
int digit_counter(size_t cmd_num)
{
	int digit_count = 0;

	if (cmd_num == 0)
		return (1);
	while (cmd_num != 0)
	{
		cmd_num /= 10;
		digit_count++;
	}

	return (digit_count);
}
