#include <stdio.h>
#include "sort.h"

/**
 * insertion_sort_list - sort doubly list data types using insertion sort
 * @list: doubly linked list data type
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *tmp;
	if (list == NULL || *list == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		while (current->prev != NULL && current->n < current->prev->n)
		{
			tmp = current->prev;
			tmp->next = current->next;

			if (tmp->prev != NULL)
				tmp->prev->next = current;
			if (current->next != NULL)
				current->next->prev = tmp;
			current->prev = tmp->next;
			tmp->prev = current;
			current->next = tmp;
			if (current->prev == NULL)
				*list = current;
		}
		current = current->next;
	}
}
