#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: Address of pointer to the head node of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *swp;

	if (!list || !*list || !(*list)->next)
		return;
	temp = (*list)->next;
	while (temp)
	{
		while (temp->prev && temp->prev->n > temp->n)
		{
			swp = temp->prev;
			if (swp->prev)
				swp->prev->next = temp;
			swp->next = temp->next;
			if (swp->next)
				swp->next->prev = swp;
			temp->prev = swp->prev;
			temp->next = swp;
			swp->prev = temp;
			if (!temp->prev)
				*list = temp;
			print_list((const listint_t *)*list);
		}
		temp = temp->next;
	}
}
