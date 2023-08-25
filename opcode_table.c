#include "monty.h"

instruction_t opcodes[] = {
{"push", push},
{"pall", pall},
{"pint", pint},
{"pop", pop},
{"swap", swap},
{"add", add},
{"nop", nop},
{"sub", sub},
{"div", monty_div},
{"mul", mul},
{"mod", mod},
{"pchar", pchar},
{NULL, NULL}
};
