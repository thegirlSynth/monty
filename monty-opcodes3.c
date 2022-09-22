#include "monty.h"




/**
 * op_pchar - prints the char at the top of the stack, followed by a new line.
 * @stack: a doubly linked list
 * @number: the line number
 */

void op_pchar(stack_t **stack, unsigned int number)
{
	stack_t *current = *stack;
	int num;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", number);
		free_all();
		exit(EXIT_FAILURE);
	}

	while (current->next != NULL)
		current = current->next;

	num = current->n;
	if (num < 32 || num >= 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", number);
		free_all();
		exit(EXIT_FAILURE);
	}

	putchar(num);
	putchar('\n');
}

