#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * main - Entry point for the Monty interpreter
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */

#define INIT_LINE_BUF_SIZE 128
extern instruction_t opcodes[];

int main(int argc, char *argv[])
{
	char *line = NULL;
	unsigned int line_number = 0;
	char *opcode;
	int found;
	int i;
	FILE *file;
	stack_t *stack = NULL;
	size_t line_buf_size = INIT_LINE_BUF_SIZE;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	
	line = malloc(line_buf_size);

	while (fgets(line, line_buf_size, file) != NULL)
	{
		line_number++;
		opcode = strtok(line, " \t\n");
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
			fclose(file);
		}
	}
	free(line);
	fclose(file);
	return (EXIT_SUCCESS);
}
