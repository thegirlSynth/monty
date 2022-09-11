#include "monty.h"

FILE *filedes;
char *buffer;
stack_t *top_stack;
/**
 * tokenize - split lines into words.
 * @buffer: the line of text to be split.
 * Return: an array of words.
 */

char **tokenize(char *buffer)
{
	int index = 0;
	char **args, *token;

	args = malloc(sizeof(char *) * strlen(buffer));
	if (args == NULL)
		return (NULL);

	if(strlen(buffer) == 1)
	{
		free(args);
		return (NULL);
	}

	token = strtok(buffer, " ");

	while (token != NULL)
	{
		args[index] = token;
		index++;
		token = strtok(NULL, " ");
	}

	args[index] = NULL;

	return (args);
}


void free_all(void)
{
	stack_t *current;

	fclose(filedes);
	free(buffer);
	if(args != NULL)
	{
		free(args);

		while (top_stack != NULL)
		{
			current = top_stack;
			top_stack = top_stack->next;
			free(current);
		}
	}
}
