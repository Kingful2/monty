#include "monty.h"

/**
 * pop_opcode - This removes the top element of the stack
 * @queues: pointer to the top of the stack
 * @line_number: line number of the opcode
 **/
void pop_opcode(stack_t **queues, unsigned int line_number)
{
	stack_t *temp;

	if (*queues == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free(glob.line);
		free_list(*queues);
		exit(EXIT_FAILURE);
	}

	temp = (*queues)->next;
	free(*queues);

	*queues = temp;

	if (*queues != NULL)
		(*queues)->prev = NULL;
}
