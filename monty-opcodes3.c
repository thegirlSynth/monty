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


/**
 * op_pstr - prints the string starting at the top of the stack, followed by a new line.
 * @stack: a doubly linked list
 * @number: the line number
 */

void op_pstr(stack_t **stack, __attribute__((unused))unsigned int number)
{
	stack_t *current = *stack;
	int num;

	if (*stack == NULL)
	{
		printf("\n");
		return;
	}

	while (current->next != NULL)
		current = current->next;

	while (current != NULL)
	{
		num = current->n;

		if (num < 32 || num >= 127 || num == 0)
			break;

		putchar(num);
		current = current->prev;
	}
	putchar('\n');
}


/**
 * op_rotl - rotates the stack to the top
 *	the top element becomes the last one, and the second top element
 *	of the stack becomes the first one.
 * @stack: a doubly linked list
 * @number: the line number
 */

void op_rotl(stack_t **stack, __attribute__((unused))unsigned int number)
{
	stack_t *current = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	while (current->next != NULL)
		current = current->next;

	current->prev->next = NULL;
	current->prev = NULL;
	current->next = *stack;
	(*stack)->prev = current;
	*stack = current;
}


/**
 * op_rotr - rotates the stack to the bottom
 *	the last element becomes the top one
 * @stack: a doubly linked list
 * @number: the line number
 */

void op_rotr(stack_t **stack, __attribute__((unused))unsigned int number)
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
