#include "sort.h"

/**
 * bubble_sort - function that sorts an array of integers in ascending
 * @array: values in an array
 * @size: array size
 *
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	size_t i;
	int temp = 0;
	int swapp = 888;

	while (swapp != 0)
	{
		swapp = 0;

		for (i = 0; i < size - 1; ++i)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				swapp++;
				print_array(array, size);
			}
		}
	}
}
