#include "sort.h"



/**
 * shell_sort - shell.
 * @array: array
 * @size: size
 *
 *
 */


void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			j = i;
			while (j >= gap && array[j - gap] > array[j])
			{
				swap_func(array + j, array + (j - gap));
				j -= gap;
			}
		}
		print_array(array, size);
	}
}


/**
 * swap_func - swap
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
