#include "monty.h"

char **args;

/**
 * op_swap - swaps the top two elements of the stack
 * @stack: a doubly linked list
 * @number: the line number
 */

void op_swap(stack_t **stack, unsigned int number)
{
	stack_t *swap = *stack, *last_node;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", number);
		free_all();
		exit(EXIT_FAILURE);
	}

	while (swap->next != NULL)
		swap = swap->next;

	last_node = swap->prev;

	/**Swapping in Progress...*/
	swap->prev = last_node->prev;
	swap->next = last_node;
	last_node->next = NULL;
	if (last_node->prev != NULL)
		last_node->prev->next = swap;
	else
		*stack = swap;

	last_node->prev = swap;

}


/**
 * op_calc - performs basic math operations on the second top element
 *		and the top element of the stack respectively, and stores the
 *		value in the second top element, and pops the top element.
 *
 * @stack: a doubly linked list
 * @number: the line number
 */

void op_calc(stack_t **stack, unsigned int number)
{
	int value;
	stack_t *last_node = *stack, *op_node;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't %s, stack too short\n", number, args[0]);
		free_all();
		exit(EXIT_FAILURE);
	}

	while (last_node->next != NULL)
		last_node = last_node->next;

	op_node = last_node->prev;

	/* Math operations in Progress....haha */
	value = do_calc(op_node->n, last_node->n, number);

	/* Reassigning and Popping */
	op_node->n = value;
	op_pop(stack, number);

}


/**
 * do_calc - performs basic math operations on two numbers
 *
 * @a: the first number
 * @b: the second number
 * @number: the line number
 * Return: the new value
 */

int do_calc(int a, int b, unsigned int number)
{
	if (strcmp(args[0], "add") == 0)
		return (a + b);

	if (strcmp(args[0], "sub") == 0)
		return (a - b);

	if (strcmp(args[0], "mul") == 0)
		return (a * b);

	if (b == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", number);
		free_all();
		exit(EXIT_FAILURE);
	}

	if (strcmp(args[0], "div") == 0)
		return (a / b);

	return (a % b);
}
