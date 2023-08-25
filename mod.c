#include "monty.h"
/**
 * mod - Computes the rest of division of the
 * second top element by the top element
 * @stack: Double pointer to the stack
 * @line_number: Line number being processed
 */
void mod(stack_t **stack, unsigned int line_number)
{
	int second_top;
	int top;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	second_top = (*stack)->n;
	top = (*stack)->next->n;
	(*stack)->next->n = top % second_top;
	pop(stack, line_number);
}
