#include "monty.h"


/**
 * monty_ops - executes monty operations.
 * @buffer: line of text from a monty file.
 */

void monty_ops(char **args, unsigned int line_number)
{
	int op_func;


	fprintf(stdout, "%s\n", args[0]);
	fprintf(stdout, "%ld\n", strlen(args[0]));
	op_func = check_func(args[0]);
	if (op_func == 0)
		return;

	fprintf(stderr, "L%u: unknown instruction <opcode>\n", line_number);

}


/**
 * check_func - selects the correct opcode to perform
 * @opcode: the string to be compared
 * Return: 0, on success
 */

int check_func(char *op_code)
{
	instruction_t ops[] = {
		{"push", op_push},
		{"pall", op_pall},
		{NULL, NULL}
	};
	int index = 0;

	while(ops[index].opcode != NULL)
	{
		if (strcmp(ops[index].opcode, op_code) == 0)
		{
			printf("checkfunc successful!\n");
			return (0);
		}
		index++;
	}

	return (-1);
}

