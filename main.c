#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

#define INIT_LINE_BUF_SIZE 128

/**
 * execute_bytecode_file - Execute Monty bytecode from a file
 * @filename: Name of the bytecode file to execute
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int execute_bytecode_file(const char *filename);

/**
 * cleanup_stack - Free all memory used by the stack
 * @stack: Pointer to the stack
 */
void cleanup_stack(stack_t **stack);

/**
 * main - Entry point for the Monty interpreter
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	return (execute_bytecode_file(argv[1]));
}

/**
 * execute_bytecode_file - Execute Monty bytecode from a file
 * @filename: Name of the bytecode file to execute
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int execute_bytecode_file(const char *filename)
{
	char *line = NULL;
	unsigned int line_number = 0;
	char *opcode;
	int found;
	int i;
	FILE *file;
	stack_t *stack = NULL;
	size_t line_buf_size = INIT_LINE_BUF_SIZE;

	file = fopen(filename, "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		return (EXIT_FAILURE);
	}
	line = malloc(line_buf_size);
	if (!line)
	{
		fprintf(stderr, "Error: Memory allocation failed\n");
		fclose(file);
		return (EXIT_FAILURE);
	}
	while (fgets(line, line_buf_size, file) != NULL)
	{
		line_number++;
		if (line[0] == '#')
			continue;
		opcode = strtok(line, " \t\n\b");
		found = 0;
		for (i = 0; opcodes[i].opcode != NULL; i++)
		{
			if (strcmp(opcodes[i].opcode, opcode) == 0)
			{
				opcodes[i].f(&stack, line_number);
				found = 1;
				break;
			}
		}
		if (!found)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
			free(line);
			cleanup_stack(&stack);
			fclose(file);
			return (EXIT_FAILURE);
		}
	}
	free(line);
	cleanup_stack(&stack);
	fclose(file);
	return (EXIT_SUCCESS);
}

/**
 * cleanup_stack - Free all memory used by the stack
 * @stack: Pointer to the stack
 */
void cleanup_stack(stack_t **stack)
{
	while (*stack != NULL)
	{
		stack_t *temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}
