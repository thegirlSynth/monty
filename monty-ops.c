#include "monty.h"


/**
 * monty_ops - executes monty operations.
 * @buffer: line of text from a monty file.
 */

void monty_ops(char *buffer, unsigned int line_number)
{
	char op_code[4];
	int index, op_func;


	if(strlen(buffer) > 3)
	{
		for (index = 0; index <= 3; index++)
			op_code[index] = buffer[index];

		fprintf(stdout, "%s\n", op_code);
		fprintf(stdout, "%ld\n", strlen(op_code));
		op_func = check_func(op_code);
		if (op_func == 0)
			return;
	}

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

