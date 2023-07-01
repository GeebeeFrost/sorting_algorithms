#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: array to be sorted
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, swp;
	int smallest;

	if (!array || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		smallest = array[i];
		j = i + 1;
		while (j < size)
		{
			if (array[j] < smallest)
			{
				smallest = array[j];
				swp = j;
			}
			j++;
		}
		if (array[i] != smallest)
		{
			array[swp] = array[i];
			array[i] = smallest;
			print_array(array, size);
		}
	}
}
