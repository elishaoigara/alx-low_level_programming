#include "monty.h"
/**
 * insertelement - insert element to the head pile
 * @head: head of the pile
 * @n: new_value
 * Return: no output =
*/
void insertelement(pile_t **head, long n)
{
    pile_t *new_element, *aux;

    aux = *head;
    new_element = malloc(sizeof(pile_t));
    if (new_element == NULL)
    {
        printf("Error\n");
        exit(0);
    }
    if (aux)
        aux->prev = new_element;
    new_element->n = n;
    new_element->next = *head;
    new_element->prev = NULL;
    *head = new_element;
}

