#include "sort.h"

/**
 * swap_ints - Swap two integers.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 *
 * Description: This function swaps the values of two
 * integers pointed to by @a and @b.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - Sorts an array of integers
 * in ascending order using selection sort.
 * @array: Pointer to the first element of the array.
 * @size: The number of elements in the array.
 *
 * Description: This function sorts the given array of integers
 *              in ascending order using the Selection Sort algorithm.
 *              It prints the array after each swap operation.
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = array + i;
		for (j = i + 1; j < size; j++)
			min = (array[j] < *min) ? (array + j) : min;

		if ((array + i) != min)
		{
			swap_ints(array + i, min);
			print_array(array, size);
		}
	}
}
