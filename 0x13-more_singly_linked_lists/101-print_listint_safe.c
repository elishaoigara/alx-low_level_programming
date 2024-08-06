#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_listint_safe - Prints a listint_t linked list.
 * @head: A pointer to the head of the listint_t list.
 *
 * Return: The number of nodes in the list.
 *         Exits with status 98 if the function fails.
 */
size_t print_listint_safe(const listint_t *head)
{
    size_t node_count = 0;
    const listint_t *current = head;
    const listint_t **visited = NULL;
    size_t i;

    while (current != NULL)
    {
        /* Allocate/reallocate memory to store visited nodes */
        for (i = 0; i < node_count; i++)
        {
            if (current == visited[i])
            {
                printf("-> [%p] %d\n", (void *)current, current->n);
                free(visited);
                return (node_count);
            }
        }
        
        node_count++;
        visited = realloc(visited, node_count * sizeof(listint_t *));
        if (visited == NULL)
        {
            exit(98);
        }
        visited[node_count - 1] = current;
        printf("[%p] %d\n", (void *)current, current->n);
        current = current->next;
    }

    free(visited);
    return (node_count);
}

