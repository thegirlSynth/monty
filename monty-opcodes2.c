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
