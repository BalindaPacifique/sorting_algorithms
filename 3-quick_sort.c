#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - Swap two integers in an array.
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
 * lomuto_partition - Order a subset of an array of integers
 * according to the lomuto
 * @array: array of integers
 * @size: size of the array
 * @left: starting index of the subset to order
 * @right: ending index of the subset to order
 *
 * Return: final partition index
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, high, low;

	pivot = array + right;
	for (high = low = left; low < right; low++)
	{
		if (array[low] < *pivot)
		{
			if (high < low)
			{
				swap_ints(array + low, array + high);
				print_array(array, size);
			}
			high++;
		}
	}

	if (array[high] > *pivot)
	{
		swap_ints(array + high, pivot);
		print_array(array, size);
	}

	return (high);
}

/**
 * lomuto_sort - Implement the quicksort algorithm through recursion
 * @array: array of integers
 * @size: size of the array
 * @left: starting index of the array partition to order
 * @right: ending index of the array partition to order
 *
 * Description: Uses the Lomuto partition scheme
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int party;

	if (right - left > 0)
	{
		party = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, party - 1);
		lomuto_sort(array, size, party + 1, right);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending order
 * @array: array of integers
 * @size: size of the array
 *
 * Description: Uses the Lomuto partition scheme.
 * Prints the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
