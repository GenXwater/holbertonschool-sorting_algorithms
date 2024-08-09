#include "sort.h"

/**
 * _swap - Swaps two elements in an array
 * @value1: Pointer to the first element
 * @value2: Pointer to the second element
 */
void _swap(int *value1, int *value2)
{
	int temp;

	temp = *value1;
	*value1 = *value2;
	*value2 = temp;
}

/**
 * lomuto_partition - Partitions the array and returns the pivot index
 * @array: The array to partition
 * @low: Starting index of the partition to sort
 * @high: Ending index of the partition to sort
 * @size: Number of elements in the array
 * Return: The pivot index
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				_swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}

	if (array[i + 1] != array[high])
	{
		_swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * _quick_sort - Recursive function to perform Quick Sort
 * @array: The array to sort
 * @low: Starting index of the partition to sort
 * @high: Ending index of the partition to sort
 * @size: Number of elements in the array
 */
void _quick_sort(int *array, int low, int high, size_t size)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = lomuto_partition(array, low, high, size);
		_quick_sort(array, low, pivot_index - 1, size);
		_quick_sort(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: The array to sort
 * @size: Number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}

	_quick_sort(array, 0, size - 1, size);
}

