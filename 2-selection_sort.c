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
	int sorted, *min;
	size_t i, j;

	if (size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		min = (array + i);
		sorted = 0;
		for (j = i + 1; j < size; j++)
		{
			if (array[j - 1] > array[j])
				sorted = 1;
			if (array[j] < *min)
				min = (array + j);
		}
		if (sorted == 0)
			return;

		swap(&array[i], min);
		print_array(array, size);
	}
}
