#include "monty.h"
/**
 * f_divideide - divide the top two elements of the pile.
 * @head: pile head
 * @counter: line_number
 * Return: no output =
*/
void f_divideide(pile_t **head, unsigned long counter)
{
    pile_t *h;
    long len = 0, aux;

    h = *head;
    while (h)
    {
        h = h->next;
        len++;
    }
    if (len < 2)
    {
        fprintf(stderr, "L%d: can't divide, pile too short\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_pile(*head);
        exit(EXIT_FAILURE);
    }
    h = *head;
    if (h->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_pile(*head);
        exit(EXIT_FAILURE);
    }
    aux = h->next->n / h->n;
    h->next->n = aux;
    *head = h->next;
    free(h);
}

