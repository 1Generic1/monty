## Monty language

Monty 0.98 is a scripting language that is first compiled into monty byte codes (Just like python). It relies on a unique stack, with specific instructions to manipulate it. monty is an interpreter built specially for the said Monty Bytecodes files.

## More About the Monty language

This is a language that contains specific instructions to manipulate data information (stacks or queues), where each instruction (called opcode) is sended per line. Files which contains Monty byte codes usually have the .m extension.

Example (file.m):

    - $ cat file.m
    - # Pushing element to the stack
    - push 0
    - push 1
    - push 2
    - # Printing all elements
    - pall
    - push 3
    - push 4
    - pop
    - # Rotating the stack to the bottom
    - rotr
    - pall
    - rotl
    - # Setting FIFO
    - queue
    - push 5
    - # Setting LIFO
    - stack
    - push 5
    - $

## usage 

TO compile all files 
	
    - $ gcc -Wall -Werror -Wextra -pedantic *.c -o monty
    - $

## Technologies

    - Interpreter was written with C language
    - C files are compiled using gcc 4.8.4
    - C files are written according to the C90 standard
    - Tested on Ubuntu 20.04 LTS

AUTHORS
- Kelvin chibuzo
- Eungobs
