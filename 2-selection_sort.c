#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * @array: array of integers to sort
 * @size: size of the array
 * Return: Exit the function if array is NULL or size is less than 2
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;
	int temp;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;

		/* Find the smallest element in the unsorted portion of the array */
		j = i + 1;
		while (j < size)
		{
			if (array[j] < array[min_idx])
				min_idx = j;
			j++;
		}

		/* Swap the found minimum element with the first element */
		if (min_idx != i)
		{
			temp = array[i];
			array[i] = array[min_idx];
			array[min_idx] = temp;

			print_array(array, size);
		}
	}
}

