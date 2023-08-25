#include "monty.h"

/**
 * sub - Subtracts the top element from the second top element of the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number being processed
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int second_top;
	int top;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	second_top = (*stack)->n;
	top = (*stack)->next->n;
	(*stack)->next->n = top - second_top;
	pop(stack, line_number);
}
