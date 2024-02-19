#include "sort.h"

int get_max(int *array, int size);
void radix_counting_sort(int *array, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);

/**
 * get_max - Find the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 *
 * Description: This function iterates through
 * the array to find and return the maximum integer.
 */
int get_max(int *array, int size)
{
	int max, i;

	for (max = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * radix_counting_sort - Sort the significant digits of an array of integers
 *                       in ascending order using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * @sig: The significant digit to sort on.
 * @buff: A buffer to store the sorted array.
 *
 * Description: This function sorts the array based
 * on the significant digit specified by 'sig'.
 * It uses the counting sort algorithm to sort the significant digits.
 */
void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
	int count[10] = {0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / sig) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		buff[count[(array[i] / sig) % 10] - 1] = array[i];
		count[(array[i] / sig) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = buff[i];
}

/**
 * radix_sort - Sort an array of integers in ascending order using radix sort.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: This function sorts the array of integers in ascending order
 * using the radix sort algorithm. It sorts the array based
 * on significant digits,
 * starting from the least significant digit (LSD).
 * It prints the array after each
 * significant digit increase.
 */
void radix_sort(int *array, size_t size)
{
	int max, sig, *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	max = get_max(array, size);
	for (sig = 1; max / sig > 0; sig *= 10)
	{
		radix_counting_sort(array, size, sig, buff);
		print_array(array, size);
	}

	free(buff);
}
