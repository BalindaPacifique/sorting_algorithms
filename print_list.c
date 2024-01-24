#include <stdio.h>
#include "sort.h"

/**
 * print_list - Prints a list of integers
 *
 * @list: The list
 */
void print_list(const listint_t *list)
{
	int indx;

	indx = 0;
	while (list)
	{
		if (indx > 0)
			printf(", ");
		printf("%d", list->n);
		++indx;
		list = list->next;
	}
	printf("\n");
}
