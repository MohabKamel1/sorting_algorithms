#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: Pointer to the first integer to swap.
 * @b: Pointer to the second integer to swap.
 *
 * Description: This function swaps the values of two integers
 *              pointed to by @a and @b.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bubble_sort - Sorts an array of integers in ascending
 * order using Bubble Sort algorithm.
 * @array: Pointer to the first element of the array.
 * @size: The number of elements in the array.
 *
 * Description: This function sorts the given array of integers
 *              in ascending order using the Bubble Sort algorithm.
 *              It prints the array after each swap operation.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (!bubbly)
	{
		bubbly = true;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_ints(&array[i], &array[i + 1]);
				print_array(array, size);
				bubbly = false;
			}
		}
		len--;
	}
}
