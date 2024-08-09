#include "sort.h"

/**
 * swap - sawp ellement in array
 *
 *@a: 1st to sawp
 *@b: 2nd to swap
 */

void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
 * partition - partition array using scheme
 *
 *@low: low bound of partition
 *@high: high bound of partition
 *@size: array size
 *@array: array to sort
 *
 *Return: index pivot after partitioning
 */

int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j = low;

	for (; j < high ; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}

	if (array[i + 1] != array[high])
	{
		swap(&array[high], &array[i + 1]);
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * recur_quick_sort - recursive fonction
 *
 *@array: array to sort
 *@low: lower bound of partition
 *@high: upper boud of partition
 *@size: array size
 */

void recur_quick_sort(int *array, int low, int high, size_t size)
{
	int rota;

	if (high > low)
	{
		rota = partition(array, low, high, size);

		recur_quick_sort(array, low, rota - 1, size);
		recur_quick_sort(array, rota + 1, high, size);
	}
}

/**
 * quick_sort - sort array in ascending order
 *
 *@array: arrays to sort
 *@size: array size
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	recur_quick_sort(array, 0, size - 1, size);
}
