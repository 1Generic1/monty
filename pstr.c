#include "monty.h"

/**
 * pstr - Prints the string starting at the top of the stack.
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: Line number of the instruction in the bytecode file.
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;
	(void)line_number;

	while (node != NULL && node->n != 0 && node->n >= 0 && node->n <= 127)
	{
		printf("%c", node->n);
		node = node->next;
	}
	printf("\n");
}
