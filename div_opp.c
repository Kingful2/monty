#include "monty.h"

/**
 * _div - divides the two top element by the top element
 * @queues: double pointer to the stack
 * @line_number: The current line number in the file
 */
void _div(stack_t **queues, unsigned int line_number)
{
	int value;
	stack_t *temp;

	if (*queues == NULL || (*queues)->next == NULL)
	{
		fprintf(stderr, "L%d: Unable to div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *queues;
	if (temp->h == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	value = temp->next->h / temp->h;
	temp->next->h = value;
	*queues = temp->next;
	free(temp);
}
