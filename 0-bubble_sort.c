#include "sort.h"

/**
 * bubble_sort - sort bubble
 * @array: array of int
 * @size: size
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j = 0;
	int tmp;

	if (array == NULL || size < 2)
		return;
	while (array[j])
	{
		for (i = 0; i < size; i++)
		{
			if (i + 1 < size && array[i] > array[i + 1])
			{
				tmp = array[i + 1];
				array[i + 1] = array[i];
				array[i] = tmp;
				print_array(array, size);
			}
		}
		j++;
	}
}
