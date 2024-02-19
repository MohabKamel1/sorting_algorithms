#include "sort.h"

void swap_ints(int *a, int *b);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

/**
 * swap_ints - Swap two integers in an array.
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
 * hoare_partition - Partition an array of integers
 * according to the Hoare scheme.
 * @array: The array of integers to partition.
 * @size: The size of the array.
 * @left: The starting index of the partition.
 * @right: The ending index of the partition.
 *
 * Return: The index of the pivot element.
 *
 * Description: This function partitions the array using the Hoare scheme
 * with the pivot being the last element. It prints the array after each swap
 * of two elements.
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot, above, below;

	pivot = array[right];
	for (above = left - 1, below = right + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < pivot);
		do {
			below--;
		} while (array[below] > pivot);

		if (above < below)
		{
			swap_ints(array + above, array + below);
			print_array(array, size);
		}
	}

	return (above);
}

/**
 * hoare_sort - Implement the Quicksort algorithm
 * using the Hoare partition scheme.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the partition.
 * @right: The ending index of the partition.
 *
 * Description: This function recursively sorts
 * the array using the Hoare partition scheme.
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, part - 1);
		hoare_sort(array, size, part, right);
	}
}

/**
 * quick_sort_hoare - Sort an array of integers in ascending
 * order using QuickSort.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 *
 * Description: This function sorts the array in
 * ascending order using QuickSort
 * with the Hoare partition scheme.
 * It prints the array after each swap of two elements.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
