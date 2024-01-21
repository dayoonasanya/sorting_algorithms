#include "sort.h"


/**
 * partition_sort - scheme.
 * @array: array
 * @size: size.
 * @left: left.
 * @right: right.
 * Return: above.
 */

int partition_sort(int *array, size_t size, int left, int right)
{
	int pivot, above, below;

	pivot = array[right];
	for (above = left - 1, below = right + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < pivot);
		do {
			below--;
		} while (array[below] > pivot);

		if (above < below)
		{
			swap_func(array + above, array + below);
			print_array(array, size);
		}
	}

	return (above);
}



/**
 * hoare - recursion.
 * @array: sort.
 * @size: array.
 * @left: order.
 * @right: order.
 */

void hoare(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = partition_sort(array, size, left, right);
		hoare(array, size, left, part - 1);
		hoare(array, size, part, right);
	}
}


/**
 * quick_sort_hoare - sort.
 * @array: array.
 * @size: array.
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare(array, size, 0, size - 1);
}


/**
 * swap_func - swap.
 * @a: a.
 * @b: b.
 */

void swap_func(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
