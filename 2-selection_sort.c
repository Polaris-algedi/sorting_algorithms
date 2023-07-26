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
 * selection_sort - sorts an array of integers in ascending
 * order using the Selection sort algorithm
 *
 * @array: array to be sorted
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int min_val, min_idx, swap_true;

	if (size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		min_val = array[i];
		min_idx = i;
		swap_true = 0;

		for (j = i + 1; j < size; j++)
		{
			if (min_val > array[j])
			{
				min_val = array[j];
				min_idx = j;
				swap_true = 1;
			}
		}

		if (swap_true)
		{
			swap(&array[min_idx], &array[i]);
			print_array(array, size);
		}
	}
}

