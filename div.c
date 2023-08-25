#include "monty.h"
/**
 * div - Divides the second top element of the stack by the top element
 * @stack: Double pointer to the stack
 * @line_number: Line number being processed
 */
void monty_div(stack_t **stack, unsigned int line_number)
{
	int second_top;
	int top;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	second_top = (*stack)->next->n;
	top = (*stack)->n;
	(*stack)->next->n = second_top / top;
	pop(stack, line_number);
}
