#include "sort.h"



/**
 * head_swapped - swap
 * @list: list
 * @tail: list
 * @swapper: pointer.
 */

void head_swapped(listint_t **list, listint_t **tail, listint_t **swapper)
{
	listint_t *tmp = (*swapper)->next;

	if ((*swapper)->prev != NULL)
		(*swapper)->prev->next = tmp;
	else
		*list = tmp;
	tmp->prev = (*swapper)->prev;
	(*swapper)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *swapper;
	else
		*tail = *swapper;
	(*swapper)->prev = tmp;
	tmp->next = *swapper;
	*swapper = tmp;
}


/**
 * tail_swapped - swap.
 * @list: list
 * @tail: list
 * @swapper: pointer
 */

void tail_swapped(listint_t **list, listint_t **tail, listint_t **swapper)
{
	listint_t *tmp = (*swapper)->prev;

	if ((*swapper)->next != NULL)
		(*swapper)->next->prev = tmp;
	else
		*tail = tmp;
	tmp->next = (*swapper)->next;
	(*swapper)->prev = tmp->prev;
	if (tmp->prev != NULL)
		tmp->prev->next = *swapper;
	else
		*list = *swapper;
	(*swapper)->next = tmp;
	tmp->prev = *swapper;
	*swapper = tmp;
}


/**
 * cocktail_sort_list - sort.
 * @list: list.
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *swapper;
	bool swapped = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (swapped == false)
	{
		swapped = true;
		for (swapper = *list; swapper != tail; swapper = swapper->next)
		{
			if (swapper->n > swapper->next->n)
			{
				head_swapped(list, &tail, &swapper);
				print_list((const listint_t *)*list);
				swapped = false;
			}
		}
		for (swapper = swapper->prev; swapper != *list;
				swapper = swapper->prev)
		{
			if (swapper->n < swapper->prev->n)
			{
				tail_swapped(list, &tail, &swapper);
				print_list((const listint_t *)*list);
				swapped = false;
			}
		}
	}
}
