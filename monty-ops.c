#include "monty.h"

unsigned int line_number;
stack_t *top_stack;

/**
 * monty_ops - executes monty operations.
 * @buffer: line of text from a monty file.
 */

void monty_ops(char **args)
{
	int op_func;

	op_func = check_func(args);
	if (op_func == 0)
		return;

	fprintf(stderr, "L%u: unknown instruction <opcode>\n", line_number);
	free_all();
	exit(EXIT_FAILURE);

}


/**
 * check_func - selects the correct opcode to perform
 * @opcode: the string to be compared
 * Return: 0, on success
 */

int check_func(char **args)
{
	int index = 0;
	instruction_t ops[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"nop", NULL},
		{NULL, NULL}
	};


	while(ops[index].opcode != NULL)
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
