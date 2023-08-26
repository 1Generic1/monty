#include "monty.h"

/**
 * rotr - Rotates the stack to the bottom.
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: Line number of the instruction in the bytecode file.
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *last;
	stack_t *second_last = NULL;

	(void)line_number;
	if (*stack != NULL && (*stack)->next != NULL)
	{
		last = *stack;
		second_last = NULL;

		while (last->next != NULL)
		{
			second_last = last;
			last = last->next;
		}
		last->next = *stack;
		*stack = last;
		second_last->next = NULL;
	}
}
