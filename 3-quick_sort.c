#include "sort.h"

/**
 * swap - Exchanges the values of two integers.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 *
 * Return: void.
 */
void swap(int *a, int *b)
{
	int t = *a;  /* Store the value of *a in a temporary variable */
	*a = *b;     /* Assign the value of *b to *a */
	*b = t;      /* Assign the value stored in the temporary variable to *b */
}

/**
 * partition - Partitions the array using the last element as the pivot.
 * Elements smaller than the pivot are moved to the left of the pivot,
 * and elements greater than the pivot are moved to the right.
 * @arr: The array to be partitioned.
 * @low: The starting index of the portion of the array to partition.
 * @high: The ending index of the portion of the array to partition.
 *
 * Return: The index of the pivot after partitioning.
 */
int partition(int arr[], int low, int high)
{
	int pivot = arr[high];  /* Select the last element as the pivot */
	int i = low - 1;        /* Initialize the index for smaller element */

	/*
	 * Loop through the array from the starting index to
	 * the one before the last
	 */
	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)
		{  /* If the current elem. is smaller than the pivot */
			i++;               /* Increment the index of the smaller element */
			swap(&arr[i], &arr[j]);  /*
						  * Swap the current element with the
						  * element at index i
						  */
		}
	}
	swap(&arr[i + 1], &arr[high]);  /*
					 * Place the pivot element in the
					 * correct position
					 */
	return (i + 1);  /* Return the index of the pivot */
}

/**
 * quick_sort_recursive - Recursively applies the Quick Sort algorithm
 * to sort an array. This function divides the array into partitions
 * and sorts them.
 * @arr: The array to be sorted.
 * @low: The starting index of the array or sub-array.
 * @high: The ending index of the array or sub-array.
 * @size: The total size of the array (used for printing purposes).
 *
 * Return: void.
 */
void quick_sort_recursive(int arr[], int low, int high, size_t size)
{
	if (low < high)
	{  /* Base condition to end recursion */
		int pi = partition(arr, low, high);  /*
						      * Partition the array and get the
						      * pivot index
						      */
		print_array(arr, size);  /*
					  * Optional: Print the array after each
					  * partition (for debugging or visualization)
					  */

		quick_sort_recursive(arr, low, pi - 1, size);  /*
								* Recursively sort the
								* left partition
								*/
		quick_sort_recursive(arr, pi + 1, high, size); /*
								* Recursively sort the
								* right partition
								*/
	}
}

/**
 * quick_sort - Sorts an array of integers using the Quick Sort algorithm.
 * This function serves as the entry point for the recursive quick sort
 * function.
 * @array: The array to be sorted.
 * @size: The size of the array.
 *
 * Return: void.
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
	{  /* If the array has less than two elements, it is already sorted */
		return;
	}
	quick_sort_recursive(array, 0, size - 1, size);  /*
							  * Call the recursive
							  * quick sort function
							  * with the full array
							  */
}
