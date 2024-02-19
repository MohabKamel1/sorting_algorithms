#include "sort.h"

void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
				  size_t back);
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 * merge_subarr - Merge two sorted subarrays into one sorted subarray.
 * @subarr: The array containing the subarrays to merge.
 * @buff: A buffer to store the sorted subarray.
 * @front: The index of the first element of the first subarray.
 * @mid: The index of the last element of the first subarray.
 * @back: The index of the last element of the second subarray.
 *
 * Description: This function merges two sorted subarrays
 * into one sorted subarray.
 *              It then prints the merged subarray.
 */
void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
				  size_t back)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);

	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	for (i = front, j = mid; i < mid && j < back; k++)
		buff[k] = (subarr[i] < subarr[j]) ? subarr[i++] : subarr[j++];
	for (; i < mid; i++)
		buff[k++] = subarr[i];
	for (; j < back; j++)
		buff[k++] = subarr[j];
	for (i = front, k = 0; i < back; i++)
		subarr[i] = buff[k++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
 * merge_sort_recursive - Recursively sort a subarray of integers
 * using merge sort.
 * @subarr: The array containing the subarrays to sort.
 * @buff: A buffer to store the sorted result.
 * @front: The index of the first element of the subarray.
 * @back: The index of the last element of the subarray.
 *
 * Description: This function implements the merge sort algorithm
 *              recursively on a subarray of integers.
 */
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		merge_sort_recursive(subarr, buff, front, mid);
		merge_sort_recursive(subarr, buff, mid, back);
		merge_subarr(subarr, buff, front, mid, back);
	}
}

/**
 * merge_sort - Sort an array of integers in ascending order using merge sort.
 * @array: The array of integers to sort.
 * @size: The size of the array.
 *
 * Description: This function sorts the given array of integers
 *              in ascending order using the merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	merge_sort_recursive(array, buff, 0, size);

	free(buff);
}
