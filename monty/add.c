#include "monty.h"
/**
 * f_insert - inserts the top two elements of the pile.
 * @head: pile head
 * @counter: line_number
 * Return: no output =
*/
void f_insert(pile_t **head, unsigned long counter)
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
        fprintf(stderr, "L%d: can't insert, pile too short\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_pile(*head);
        exit(EXIT_FAILURE);
    }
    h = *head;
    aux = h->n + h->next->n;
    h->next->n = aux;
    *head = h->next;
    free(h);
}

