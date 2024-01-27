#include "sort.h"

/**
 * swap_ints - Swap two integers
 * @a: first integer
 * @b: second integer
 */
void swap_ints(int *a, int *b)
{
	int ptr;

	ptr = *a;
	*a = *b;
	*b = ptr;
}

/**
 * shell_sort - Sort an array of integers in ascending order
 * @array: array of integers
 * @size: size of the array
 *
 * Description: Uses the Knuth interval sequence
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i_1, i_2;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (i_1 = gap; i_1 < size; i_1++)
		{
			i_2 = i_1;
			while (i_2 >= gap && array[i_2 - gap] > array[i_2])
			{
				swap_ints(array + i_2, array + (i_2 - gap));
				i_2 -= gap;
			}
		}
		print_array(array, size);
	}
}
