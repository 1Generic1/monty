#include "monty.h"
#include <string.h>
#include <stdlib.h>

/**
 * pall - Prints all values on the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number being processed
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	
	(void) line_number;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
