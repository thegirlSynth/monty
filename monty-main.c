#include "monty.h"

/**
 * main - this is the entry point of the monty intepreter.
 * @argc: the number of arguments to the program
 * @argv: an array of arguments to the program.
 */

int main(int argc, char **argv)
{
	unsigned int line_number = 1;
	char *buffer;
	FILE *filedes;

	/* Ensuring the correct number of arguments */
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	/*Allocating memory for buffer*/
	buffer = malloc(sizeof(char) * 1024);
	if (buffer == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}


	/* Opening the monty file */
	filedes = fopen(argv[1], "r");
	if (filedes == NULL)
	{
		fprintf(stderr,"Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	/* Reading lines from the file */
	while((fgets(buffer, 1024, filedes)) != NULL)
	{
		buffer = strip_begin_spaces(buffer);
		monty_ops(buffer, line_number);
		line_number++;
	}

	fclose(filedes);
	free(buffer);
	return (0);
}
