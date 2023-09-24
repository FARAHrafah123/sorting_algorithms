#include "sort.h"


/**
 * lomuto_partitions - orderr a subset of an array of integers according to
 * @array: The array of integeers.
 * @size: The size of the arrayy.
 * @left: The starting indexxx of the subset to order.
 * @right: The ending indexxx of the subset to order.
 * Return: The final partitionn indexxx.
 */
int lomuto_partitions(int *array, size_t size, int left, int right)
{
	int *pivot, above, below, tmp;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				tmp = array[below];
				array[below] = array[above];
				array[above] = tmp;
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		tmp = array[below];
		array[below] = array[above];
		array[above] = tmp;
		print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_sort - Implement the quicksort algorithmm through reccursion.
 * @array: An array of integers to sorrt.
 * @size: The size of the arrayy.
 * @left: The starting indexx of the array partition to order.
 * @right: The ending indexx of the array partition to order.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partitions(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - Sort an arrayy of integerrs in ascending
 * @array: An array of integerrs.
 * @size: The size of the arrayy.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	lomuto_sort(array, size, 0, size - 1);
}
