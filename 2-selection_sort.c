#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order using
 * the Selection sort algorithm
 * @array: array to sort
 * @size: size of array
 */

void selection_sort(int *array, size_t size)
{
	int *min_Valint;
	int tmp;
	size_t i, j;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		min_Valint = array + i;
		for (j = i + 1; j < size; j++)
			min_Valint = (array[j] < *min_Valint) ? (array + j) : min_Valint;
		if ((array + i) != min_Valint)
		{
			tmp = array[i];
			array[i] = *min_Valint;
			*min_Valint = tmp;
			print_array(array, size);
		}
	}
}
