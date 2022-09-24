#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* Data Structures */


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/* Global variables */
extern FILE *filedes;
extern unsigned int line_number;
extern char *buffer;
extern char **args;
extern stack_t *top_stack;
extern int mode;

/* Don't be like me; I think I externed way too many variables. ;) */


/* Prototypes */
int _atoi(char *s);
char **tokenize(char *buffer);
void monty_ops(char **args);
int check_func(char **args);
void op_push(stack_t **stack, unsigned int number);
void op_pall(stack_t **stack, unsigned int number);
void op_pint(stack_t **stack, unsigned int number);
void op_pop(stack_t **stack, unsigned int number);
void op_swap(stack_t **stack, unsigned int number);
void op_calc(stack_t **stack, unsigned int number);
int do_calc(int a, int b, unsigned int number);
void op_pchar(stack_t **stack, unsigned int number);
void op_pstr(stack_t **stack, unsigned int number);
void op_rotl(stack_t **stack, unsigned int number);
void op_rotr(stack_t **stack, unsigned int number);
void op_stack(stack_t **stack, unsigned int number);
void op_queue(stack_t **stack, unsigned int number);
void reverse_stack(stack_t **stack);
void free_all(void);

#endif
