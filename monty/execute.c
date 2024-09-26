#include "monty.h"
/**
* run_command - runs the opcode
* @pile: head linked list - pile
* @counter: line_counter
* @file: pointer to monty file
* @content: line content
* Return: no output =
*/
long run_command(char *content, pile_t **pile, unsigned long counter, FILE *file)
{
    instruction_t opst[] = {
                {"push", f_push}, {"pall", f_pall}, {"pint", f_pint},
                {"pop", f_pop},
                {"swap", f_swap},
                {"insert", f_insert},
                {"nop", f_nop},
                {"sub", f_sub},
                {"divide", f_divideide},
                {"mul", f_mul},
                {"mod", f_mod},
                {"pchar", f_pchar},
                {"pstr", f_pstr},
                {"rotl", f_rotl},
                {"rotr", f_rotr},
                {"queue", f_queue},
                {"stack", f_stack},
                {NULL, NULL}
                };
    unsigned long i = 0;
    char *op;

    op = strtok(content, " \n\t");
    if (op && op[0] == '#')
        return (0);
    bus.arg = strtok(NULL, " \n\t");
    while (opst[i].opcode && op)
    {
        if (strcmp(op, opst[i].opcode) == 0)
        {
            opst[i].f(pile, counter);
            return (0);
        }
        i++;
    }
    if (op && opst[i].opcode == NULL)
    {
        fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
        fclose(file);
        free(content);
        free_pile(*pile);
        exit(EXIT_FAILURE);
    }
    return (1);
}

