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
	unsigned int len = strlen(buffer);
	char **args, *token;

	args = malloc(sizeof(char *) * strlen(buffer));
	if (args == NULL)
		return (NULL);

	if (len == 1)
	{
		free(args);
		return (NULL);
	}

	buffer[len - 1] = '\0';

	token = strtok(buffer, " $");

	while (token != NULL)
	{
		args[index] = token;
		index++;
		token = strtok(NULL, " $");
	}

	args[index] = NULL;

	return (args);
}


/**
 * _atoi - converts a string to an integer
 * @s: string to be converted
 *
 * Return: the int converted from the string
 */

int _atoi(char *s)
{
	int i, d, n, len, digit;

	i = 0;
	d = 0;
	n = 0;
	len = 0;
	digit = 0;

	while (s[len] != '\0')
	{
		len++;
	}

	while (i < len && s[i] != '\0')
	{
		if (s[i] == '-')
			++d;

		if (s[i] >= '0' && s[i] <= '9')
		{
			digit = s[i] - '0';
			if (d % 2)
				digit = -digit;
			n = n * 10 + digit;
			if ((s[i + 1] < '0' || s[i + 1] > '9') && s[i + 1] != '\0')
				return (0);
		}
		i++;
	}
	return (n);
}


/**
 * free_all - frees malloced addresses
 */

void free_all(void)
{
	stack_t *current;

	fclose(filedes);
	free(buffer);
	if (args != NULL)
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
