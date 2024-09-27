#include "monty.h"

/**
 * free_list - frees a stack_t list
 * @queues: pointer to the top of the stack
 */
void free_list(stack_t *queues)
{
	stack_t *current;

	while (queues != NULL)
	{
		current = queues;
		queues = queues->next;
		free(current);
	}
}
