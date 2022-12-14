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

	/* Handling Comments */
	if (**args == '#')
		return;

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
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		{"add", op_calc},
		{"sub", op_calc},
		{"mul", op_calc},
		{"div", op_calc},
		{"mod", op_calc},
		{"pchar", op_pchar},
		{"pstr", op_pstr},
		{"rotl", op_rotl},
		{"rotr", op_rotr},
		{"stack", op_stack},
		{"queue", op_queue},
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
