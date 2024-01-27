#include "sort.h"

/**
 * get_max - Get the maximum value in an array
 * @array: array of integers
 * @size: size of the array
 *
 * Return: maximum integer in the array
 */
int get_max(int *array, int size)
{
	int high, indx;

	for (high = array[0], indx = 1; indx < size; indx++)
	{
		if (array[indx] > high)
			high = array[indx];
	}

	return (high);
}

/**
 * counting_sort - Sort an array of integers in ascending order
 * @array: An array
 * @size: size of the array
 *
 * Description: Prints the counting array after setting it up
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted, high, indx;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	high = get_max(array, size);
	count = malloc(sizeof(int) * (high + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (indx = 0; indx < (high + 1); indx++)
		count[indx] = 0;
	for (indx = 0; indx < (int)size; indx++)
		count[array[indx]] += 1;
	for (indx = 0; indx < (high + 1); indx++)
		count[indx] += count[indx - 1];
	print_array(count, high + 1);

	for (indx = 0; indx < (int)size; indx++)
	{
		sorted[count[array[indx]] - 1] = array[indx];
		count[array[indx]] -= 1;
	}

	for (indx = 0; indx < (int)size; indx++)
		array[indx] = sorted[indx];

	free(sorted);
	free(count);
}
