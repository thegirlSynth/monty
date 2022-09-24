#include "monty.h"

int mode;

/**
 * stack_an_queue - changes the data format from LIFO to FIFO, and vice versa
 *	essentially reverses the stack
 * @stack: a doubly linked list
 * @number: the line number
 */

void op_stack(stack_t **stack, unsigned int number)
{
	(void)stack;
	(void)number;
	mode = 1;
}



void op_queue(stack_t **stack, unsigned int number)
{
	(void)stack;
	(void)number;
	mode = 2;
}



/**
 * reverse_stack - changes the data format from LIFO to FIFO, and vice versa
 *	essentially reverses the stack
 * @stack: a doubly linked list
 */

void reverse_stack(stack_t **stack)
{
	stack_t *current = *stack, *lastnode;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	while (current->next != NULL)
		current = current->next;

	lastnode = current->prev;
	current->next = lastnode;
	current->prev = NULL;
	*stack = current;

	while (lastnode != NULL)
	{
		lastnode->next = lastnode->prev;
		lastnode->prev = current;
		current = lastnode;
		lastnode = lastnode->next;
	}
}
