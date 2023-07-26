#include "headers.h"

/**
 * free_listtoken - frees a linked list of tokens
 * @head: pointer to the head of the linked list
 *
 * Return: void
 */
void free_listtoken(listtoken_t **head)
{
	listtoken_t *node;

	if (head == NULL)
		return;

	while (*head != NULL)
	{
		node = *head;
		*head = node->next;
		free(node->token);
		free(node);
	}
	head = NULL;
}
