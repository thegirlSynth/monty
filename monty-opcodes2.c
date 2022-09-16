#include "monty.h"


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
 * op_add - adds the top two elements of the stack, stores the value
 * in the second top element, and pops the top element.
 *
 * @stack: a doubly linked list
 * @number: the line number
 */

void op_add(stack_t **stack, unsigned int number)
{
	int sum;
	stack_t *last_node = *stack, *add_node;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", number);
		free_all();
		exit(EXIT_FAILURE);
	}

	while (last_node->next != NULL)
		last_node = last_node->next;

	add_node = last_node->prev;

	/* Adding the last two elements and storing in the second last element*/
	sum = add_node->n + last_node->n;
	add_node->n = sum;
	op_pop(stack, number);

}


/**
 * op_sub - subtracts the top element from the second top element of the stack,
 * stores the value in the second top element, and pops the top element.
 *
 * @stack: a doubly linked list
 * @number: the line number
 */

void op_sub(stack_t **stack, unsigned int number)
{
	int diff;
	stack_t *last_node = *stack, *sub_node;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", number);
		free_all();
		exit(EXIT_FAILURE);
	}

	while (last_node->next != NULL)
		last_node = last_node->next;

	sub_node = last_node->prev;

	/* Subtracting in Progress*/
	diff = sub_node->n - last_node->n;
	sub_node->n = diff;
	op_pop(stack, number);

}
