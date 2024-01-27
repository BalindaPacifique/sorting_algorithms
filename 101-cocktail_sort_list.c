#include "sort.h"

void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker);
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker);
void cocktail_sort_list(listint_t **list);

/**
 * swap_node_ahead - Swap a node in a listint_t doubly-linked list
 * @list: pointer to the head
 * @tail: pointer to the tail
 * @shaker: A pointer to the current swapping node
 */
void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *ptr = (*shaker)->next;

	if ((*shaker)->prev != NULL)
		(*shaker)->prev->next = ptr;
	else
		*list = ptr;
	ptr->prev = (*shaker)->prev;
	(*shaker)->next = ptr->next;
	if (ptr->next != NULL)
		ptr->next->prev = *shaker;
	else
		*tail = *shaker;
	(*shaker)->prev = ptr;
	ptr->next = *shaker;
	*shaker = ptr;
}

/**
 * swap_node_behind - Swap a node in a listint_t doubly-linked
 * @list: pointer to the head
 * @tail: pointer to the tail
 * @shaker: A pointer to the current swapping node
 */
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *ptr = (*shaker)->prev;

	if ((*shaker)->next != NULL)
		(*shaker)->next->prev = ptr;
	else
		*tail = ptr;
	ptr->next = (*shaker)->next;
	(*shaker)->prev = ptr->prev;
	if (ptr->prev != NULL)
		ptr->prev->next = *shaker;
	else
		*list = *shaker;
	(*shaker)->next = ptr;
	ptr->prev = *shaker;
	*shaker = ptr;
}

/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list of integers
 * @list: A pointer to the head
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *shaker;
	bool shaken_not_stirred = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (shaken_not_stirred == false)
	{
		shaken_not_stirred = true;
		for (shaker = *list; shaker != tail; shaker = shaker->next)
		{
			if (shaker->n > shaker->next->n)
			{
				swap_node_ahead(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
		for (shaker = shaker->prev; shaker != *list;
				shaker = shaker->prev)
		{
			if (shaker->n < shaker->prev->n)
			{
				swap_node_behind(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
	}
}
