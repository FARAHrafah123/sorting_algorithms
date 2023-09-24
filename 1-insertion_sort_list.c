#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - inserts right unsortted side into left sorted side
 * @list: doubly linked list to sort
 *
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *last, *tmp;

	if (!list || !(*list) || !(*list)->next)
		return;

	current = (*list)->next;
	while (current)
	{
		last = current->prev;
		tmp = current->next;
		while (last && current->n < last->n)
		{
			if (last->prev)
				last->prev->next = current;
			last->next = current->next;
			current->next = last;
			current->prev = last->prev;
			last->prev = current;
			if (last->next)
				last->next->prev = last;
			if (!current->prev)
				(*list) = current;
			print_list(*list);
			last = current->prev;
		}
		current = tmp;
	}
}
