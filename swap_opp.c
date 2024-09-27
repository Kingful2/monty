#include "monty.h"

/**
 * swap_top - swaps the top two value
 * @queues: pointer to the top of the stack
 * @line_number: line number
*/
void swap_top(stack_t **queues, unsigned int line_number)
{
	stack_t *temp;

	if (*queues == NULL || (*queues)->next == NULL)
	{
		fprintf(stderr, "L%d: Unable to  swap, too short\n", line_number);
		free(glob.line);
		free_list(*queues);
		exit(EXIT_FAILURE);
	}

	temp = (*queues)->next;
	(*queues)->next = temp->next;

	if (temp->next != NULL)

	temp->next->prev = *queues;
	temp->prev = NULL;
	temp->next = *queues;
	(*queues)->prev = temp;
	*queues = temp;
}
