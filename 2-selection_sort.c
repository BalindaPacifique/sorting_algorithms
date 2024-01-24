#include "sort.h"

/**
 * swap_ints - swap 2 integers in an array
 * @a: The first integer
 * @b: The second integer
 */
void swap_ints(int *a, int *b)
{
	int ptr;

	ptr = *a;
	*a = *b;
	*b = ptr;
}

/**
 * selection_sort - Sort an array of integers in ascending order
 * @array: array of integers.
 * @size: size of the array.
 *
 * Description: Prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t indx1, indx2;

	if (array == NULL || size < 2)
		return;

	for (indx1 = 0; indx1 < size - 1; indx1++)
	{
		min = array + indx1;
		for (indx2 = indx1 + 1; indx2 < size; indx2++)
			min = (array[indx2] < *min) ? (array + indx2) : min;

		if ((array + indx1) != min)
		{
			swap_ints(array + indx1, min);
			print_array(array, size);
		}
	}
}
