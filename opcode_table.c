#include "monty.h"
instruction_t opcodes[] = {
    {"push", push},
    {"pall", pall},
    {"pint", pint},
    /* Add more opcode definitions here */
    {NULL, NULL}
};
