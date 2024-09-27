#include "monty.h"

/**
 * add_nodeint - To adds a new node at the beginning of a stack_t list
 * @queues: pointer to pointer to linked list
 * @h: value to be added to the new node
 *
 * Return: pointer to the newly added node
 */
stack_t *add_nodeint(stack_t **queues, const int h)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: Usage failed\n");
		free_list(*queues);
		exit(EXIT_FAILURE);
	}

	new_node->h = h;
	new_node->prev = NULL;

	if (*queues == NULL)
		new_node->next = NULL;
	else
	{
		new_node->next = *queues;
		(*queues)->prev = new_node;
	}
	*queues = new_node;

	return (new_node);
}
