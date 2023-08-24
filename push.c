#include "monty.h"
#include <string.h>
#include <stdlib.h>

/**
 * push - Pushes an element onto the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number being processed
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *arg = strtok(NULL, " \t\n");
	stack_t *new_node;

	if (arg == NULL || !is_integer(arg))
	{
		printf("Invalid argument or not an integer\n");
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = atoi(arg);
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;
}
