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
 * bubble_sort - sorts an array of integers in ascending
 * order using the Bubble sort algorithm
 *
 * @array: array to be sorted
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	int swap_count;
	size_t i, j;

	if (size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		swap_count = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap_count++;
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
			}
		}
		if (swap_count == 0)
			return;
	}
}
