#include "monty.h"

unsigned int line_number;
stack_t *top_stack;

/**
 * monty_ops - executes monty operations.
 * @args: array of arguements from a monty file.
 */

void monty_ops(char **args)
{
	int op_func;

	op_func = check_func(args);
	if (op_func == 0)
		return;

	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, args[0]);
	free_all();
	exit(EXIT_FAILURE);

}


/**
 * check_func - selects the correct opcode to perform
 * @args: arrays of strings
 * Return: 0, on success
 */

int check_func(char **args)
{
	int index = 0;
	instruction_t ops[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"nop", NULL},
		{"pop", op_pop},
		{NULL, NULL}
	};


	while (ops[index].opcode != NULL)
	{
		if (strcmp(ops[index].opcode, args[0]) == 0)
		{
			if (index != 2)
				ops[index].f(&top_stack, line_number);
			return (0);
		}
		index++;
	}


	return (-1);
}
