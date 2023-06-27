#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 * @array: Pointer to the array
 * @size: Size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, rep = 0, temp;
	int swap_flag = 0;

	while (array && rep++ < size)
	{
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				swap_flag = 1;
				print_array(array, size);
			}
		}
		if (!swap_flag)
			break;
	}
}
