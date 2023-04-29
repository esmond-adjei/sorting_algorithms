#include "sort.h"

/**
 * swap_nodes - swaps nodes in a doubly linked list
 * @list: pointer to the head of the list
 * @node1: first node
 * @node2: second node
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev != NULL)
		node1->prev->next = node2;
	else
		*list = node2;

	if (node2->next != NULL)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;
	node2->next = node1;
	node1->prev = node2;
	print_list(*list);
}

/**
 * is_valid_list - checks valid doubly linked list (not circular)
 * @head: head of the list
 * Return - 1 if valid list else 0
 */
int is_valid_list(listint_t *head)
{
	listint_t *slow = head;
	listint_t *fast = head;

	if (head == NULL)
		return (1);

	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		
		if (slow == fast)
			return (0);
	}
	return (1);
}

/**
 * insertion_sort_list - sorts a doubly linked list in ascending order
 * @list: pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr = (*list)->next;

	if (list == NULL || *list == NULL || (*list)->next == NULL \
			|| !is_valid_list(*list))
		return;

	while (curr != NULL)
	{
		listint_t *prev = curr->prev;

		while (prev != NULL && prev->n > curr->n)
		{
			swap_nodes(list, prev, curr);
			prev = curr->prev;
		}
		curr = curr->next;
	}
}
