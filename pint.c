#include "monty.h"

/**
 * pint - Print the value at the top of the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number being processed
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("%d\n", (*stack)->n);
	}
}
