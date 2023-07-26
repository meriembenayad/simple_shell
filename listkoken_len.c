#include "headers.h"

/**
 * listtoken_len - calculates the length of a linked list of tokens
 * @head: pointer to the head of the linked list
 *
 * Return: length of the linked list
 */
size_t listtoken_len(const listtoken_t *head)
{
	int count = 0;
	const listtoken_t *current;

	if (head == NULL)
		return (0);

	current = head;
	while (current != NULL)
	{
		count++;
		current = current->next;
	}

	return (count);
}
