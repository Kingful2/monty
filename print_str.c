#include "monty.h"

/**
 * print_str - prints string starting at top of the stack
 * @stack: double pointer to the top of stack.
 * @line_number: current line number of the opcode in the Monty file
 */
void print_str(stack_t **queues, unsigned int line_number)
{
	stack_t *current = *queues;
	(void) line_number;

	while (current && current->h > 0 && current->h <= 127)
	{
		printf("%c", current->h);
		current = current->next;
	}
	printf("\n");
}
