#include "sort.h"
#include <stdio.h>

/**
 * bubble_sort - sorts an array of integers in
 * ascending order using the Bubble sort algorithm
 *
 * @array - array to sort
 * @size_t - size of the array
 *
 * Return: nothing
 */
void cocktail_sort_list(listint_t **list)
{
  listint_t *curr, *prev;
  int sorted = -1;

  if (!list || *list == NULL)
    return;

  while(sorted == -1)
  {
    curr = *list;
    /* Forward Bubble Sort */
    sorted = 0;
    while (curr) {
      if (curr->next && curr->n > curr->next->n)
      {
        swap_nodes(curr, curr->next);
        sorted = -1;
        print_list(*list);
        continue;
      }
      prev = curr->prev;
      curr = curr->next;
    }
    curr = prev;

    /* Backward Bubble Sort */
    sorted = 0;
    while (curr->prev) 
    {
      if (curr->n < curr->prev->n)
      {
        swap_nodes(curr, curr->prev);
        sorted = -1;
        if (!curr->prev)
          *list = curr;
        print_list(*list);
        continue;
      }
      curr = curr->prev;
    }
  }
}

void swap_nodes(listint_t *node1, listint_t *node2)
{
  listint_t *temp;

  temp = node1->next;
  node1->next = node2->next;
  node2->next = temp;

  if (node1->next != NULL)
    node1->next->prev = node1;
  if (node2->next != NULL)
    node2->next->prev = node2;

  temp = node1->prev;
  node1->prev = node2->prev;
  node2->prev = temp;

  if (node1->prev != NULL)
    node1->prev->next = node1;
  if (node2->prev != NULL)
    node2->prev->next = node2;
}
