#include "sort.h"
/**
 * swap_ints - swap two integers in an array
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
 * bubble_sort - Sort a set of integers in ascending order
 * @array: An array of integers
 * @size: size of the array
 *
 * Description: Print array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t indx, leng = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (indx = 0; indx < leng - 1; indx++)
		{
			if (array[indx] > array[indx + 1])
			{
				swap_ints(array + indx, array + indx + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		leng--;
	}
}
