#include "monty.h"

char **args;

/**
 * op_push - pushes an element to the top of the stack
 * @stack: a doubly linked list
 * @number: the line number
 */


void op_push(stack_t **stack, unsigned int number)
{
	stack_t *new_node, *last_node = *stack;
	int value = atoi(args[1]);


	if (!args[1] || value == 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", number);
		free_all();
		exit(EXIT_FAILURE);
	}
	
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		return;

	new_node->n = value;
	new_node->next = NULL;

	if (*stack == NULL)
	{
		*stack = new_node;
		new_node->prev = NULL;
		return;
	}

	while (last_node->next != NULL)
		last_node = last_node->next;

	new_node->prev = last_node;
	last_node->next = new_node;

}


/**
 * op_pall - prints all the element in a stack
 * @stack: a doubly linked list
 * @number: the line number
 */

void op_pall(stack_t **stack, __attribute__((unused))unsigned int number)
{
	stack_t *current = *stack;

	if (*stack == NULL)
		return;

	while(current->next != NULL)
		current = current->next;

	while(current != NULL)
	{
		printf("%d\n", current->n);
		current = current->prev;
	}
}


/**
 * op_pop - removes the top element in a stack
 * @stack: a doubly linked list
 * @number: the line number
 */

void op_pop(stack_t **stack, unsigned int number)
{
	stack_t *current = *stack, *last_node;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", number);
		free_all();
		exit(EXIT_FAILURE);
	}
	
	while(current->next != NULL)
		current = current->next;

	last_node = current->prev;
	last_node->next = NULL;

	free(current);

}
