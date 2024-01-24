#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
	size_t indx;

	indx = 0;
	while (array && indx< size)
	{
		if (indx > 0)
			printf(", ");
		printf("%d", array[indx]);
		++indx;
	}
	printf("\n");
}
