#include "sort.h"



/**
 * bubble_sort - sort
 * @array: array
 * @size: size
 *
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	bool swapped = false;

	if (array == NULL || size < 2)
		return;

	while (swapped == false)
	{
		swapped = true;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_func(array + i, array + i + 1);
				print_array(array, size);
				swapped = false;
			}
		}
		len--;
	}
}


/**
 * swap_func - swap
 * @a: a
 * @b: b
 */

void swap_func(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
