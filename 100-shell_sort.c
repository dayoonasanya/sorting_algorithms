#include "sort.h"




/**
 * swap_func - swap
 *
 * @a: a.
 * @b: b.
 * Return: 0
 */


void swap_func(int *a, int *b)
{
	int tmp;

	tmp = *b;
	*b = *a;
	*a = tmp;
}



/**
 * gap_sort - sort
 * @array: array
 * @size: size
 * @gap: gap
 */

void gap_sort(int *array, size_t size, unsigned int gap)
{
	size_t j, k;

	for (j = gap; j < size; j++)
	{
		k = j;
		while (k >= gap && array[k] < array[k - gap])
		{
			swap_func(array + k, array + k - gap);
			k -= gap;
		}
	}
}



/**
 * shell_sort - shell
 * @array: array
 * @size: size
 */

void shell_sort(int *array, size_t size)
{
	unsigned int gap = 1;

	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap >= 1)
	{
		gap_sort(array, size, gap);
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
