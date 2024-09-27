#include "monty.h"

/**
 * add - This adds the top two elements of the stack
 * @queues: pointer to the top of the stack
 * @line_number: line number of the opcode
 **/
void add(stack_t **queues, unsigned int line_number)
{
	if (*queues == NULL || (*queues)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free(glob.line);
		free_list(*queues);
		exit(EXIT_FAILURE);
	}

	(*queues)->next->h += (*queues)->h;
	pop_opcode(queues, line_number);
}
