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
{"divv", divv},
{"mul", mul},
{"mod", mod},
{NULL, NULL}
};
