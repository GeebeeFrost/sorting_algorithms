#include "sort.h"

void lomuto_sort(int *, size_t, int, int);
int lomuto_partition(int *, size_t, int, int);
void swap_ints(int *, int *);

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: Array to be sorted
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	lomuto_sort(array, size, 0, size - 1);
}


/**
 * lomuto_sort - sorts an array by implementing the lomuto
 * partition scheme
 * @array: array to be sorted
 * @size: size of array
 * @left: starting index
 * @right: end index
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (left < right)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
 * lomuto_partition - Partitions an array of integers according to the
 * lomuto partition scheme
 * @array: Array to be partitioned
 * @size: size of the array
 * @left: starting index
 * @right: end index
 *
 * Return: Final partition index
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int pivot, above, below;

	pivot = array[right];
	for (above = below = left; below < right; below++)
	{
		if (array[below] < pivot)
		{
			swap_ints(&array[below], &array[above]);
			print_array((const int *)array, size);
		}
		above++;
	}
	swap_ints(&array[above], &array[right]);
	print_array((const int *)array, size);
	return (above);
}

/**
 * swap_ints - Swaps two integers in an array
 * @a: First integer
 * @b: Second integer
 */
void swap_ints(int *a, int *b)
{
	if (*a != *b)
	{
		*a = *a + *b;
		*b = *a - *b;
		*a = *a - *b;
	}
}
