#ifndef MONTY_Hi
#define MONTY_H
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/**
* struct stack_s - doubly linked list representation of a stack (or queue)
* @n: integer
* @next: points to the next element of the stack (or queue)
*
* Description: doubly linked list node structure
* for Monty project
*/

typedef struct stack_s
{
int n;
struct stack_s *next;
} stack_t;

/**
* struct instruction_s - opcode and its function
* @opcode: the opcode
* @f: function to handle the opcode
*
* Description: opcode and its associated function
*/
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern instruction_t opcodes[];
void pint(stack_t **stack, unsigned int line_number);
int is_integer(char *str);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void initialize_opcodes(void);
#endif /* MONTY_H */
