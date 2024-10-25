#include "sort.h"

/**
 * insertion_sort_list - This function sorts a doubly linked list using the
 * insertion sort algorithm.
 * @list: a double pointer to the head of the doubly linked list.
 *
 * Return: void.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *cursor1, *comp1, *comp2;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	cursor1 = *list;
	while (cursor1->next != NULL)
	{
		comp1 = cursor1;
		comp2 = cursor1->next;
		while (comp1 != NULL)
		{
			if (comp1->n > comp2->n)
			{
				if (comp1->prev == NULL)
					*list = comp2;
				comp1->next = comp2->next;
				comp2->prev = comp1->prev;
				comp2->next = comp1;
				comp1->prev = comp2;
				if (comp2->prev)
					comp2->prev->next = comp2;
				if (comp1->next)
					comp1->next->prev = comp1;
				cursor1 = comp2;
				comp1 = comp2->prev;
				print_list(*list);
			}
			else
				break;
		}
		cursor1 = cursor1->next;
	}
}
