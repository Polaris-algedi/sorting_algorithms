#include "sort.h"

/**
 * swap - swaps position of values in an array
 *
 * @a: first element
 * @b: second element
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomutoPartition - Lomuto partition function to rearrange the
 * array and return the pivot index
 *
 * @array: array to be sorted
 * @low: the low index
 * @high: the high index
 * @size: size of the array
 *
 * Return: the index of the pivot element
 */
int lomutoPartition(int *array, int low, int high, size_t size)
{
	/* Choose the last element as the pivot */
	int pivot = array[high];
	int i = low - 1, j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			if (i != j)
				print_array(array, size);
		}
	}
	swap(&array[i + 1], &array[high]);
	if (i + 1 != high)
		print_array(array, size);

	return (i + 1);
}

/**
 * quickSort - sorts an array of integers in ascending
 * order using the Quick sort algorithm
 *
 * @array: array to be sorted
 * @low: the low index
 * @high: the high index
 * @size: size of the array
 */
void quickSort(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		/* Partition the array and get the pivot index */
		int pivotIndex = lomutoPartition(array, low, high, size);

		/* Recursively call quickSort for the left and right subarrays */
		quickSort(array, low, pivotIndex - 1, size);
		quickSort(array, pivotIndex + 1, high, size);
	}
}


/**
 * quick_sort - sorts an array of integers in ascending
 * order using the Quick sort algorithm
 *
 * @array: array to be sorted
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quickSort(array, 0, size - 1, size);
}
