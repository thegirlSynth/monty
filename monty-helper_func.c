#include "monty.h"


char *strip_begin_spaces(char *buffer)
{
	unsigned int index;

	while(*buffer == ' ')
	{
		for (index = 0; index <= strlen(buffer); index++)
			buffer[index] = buffer[index + 1];
	}

	return (buffer);
}
