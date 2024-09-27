#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include <sys/types.h>
#include <stdio.h>


/**
 * struct global_s - variables -> args, file, line content
 * @arg: value
 * @line: input line content
 * @file: pointer to monty file
 *
 * Description: variables that carries values through the program
 */
typedef struct global_s
{
	char *arg;
	FILE *file;
	char *line;
} glob_t;

extern glob_t glob;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct queues_s
{
	int h;
	struct queues_s *prev;
	struct queues_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **queues, unsigned int line_number);
} instruction_t;

/* Function prototypes */
void process_line(stack_t **stack);
void exec_opcode(char *opcode, stack_t **stack, unsigned int line_number);

/* Stack helper functions */
stack_t *add_nodeint(stack_t **stack, const int h);
int is_integer(char *str);
void free_list(stack_t *stack);

void op_nothing(stack_t **stack, unsigned int line_number);
void _sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);
void _mod(stack_t **stack, unsigned int line_number);
void print_char(stack_t **stack, unsigned int line_number);
void print_str(stack_t **stack, unsigned int line_number);
void push_opcode(stack_t **stack, unsigned int line_number);
void op_pall(stack_t **stack, unsigned int line_number);
void print_int(stack_t **stack, unsigned int line_number);
void pop_opcode(stack_t **stack, unsigned int line_number);
void swap_top(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);



#endif /* monty.h */
