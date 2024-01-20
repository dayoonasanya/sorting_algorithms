#include "sort.h"

/**
 * quick_sort - array
 *
 * @array: Array to be sorted
 * @size: Size of array
 * Return: 0
 */

void quick_sort(int *array, size_t size)
{
	size_t pivot;

	if (!array || size < 2)
		return;

	print_sort(array, size, 1);

	pivot = partition(array, size);

	quick_sort(array, pivot);
	quick_sort(array + pivot, size - pivot);
}


/**
 * swap_func - swap.
 *
 * @a: a
 * @b: b
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
 * partition - set pivot
 *
 * @array: array
 * @size: size
 * Return: incrimental
 */

size_t partition(int array[], size_t size)
{
	int pivot;
	size_t i = -1;
	size_t j;

	if (!array || size < 2)
		return (0);

	pivot = array[size - 1];

	for (j = 0; j < size - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap_func(&array[i], &array[j]);
				print_sort(array, size, 0);
			}
		}
	}
	if (i + 1 != size - 1)
	{
		swap_func(&array[i + 1], &array[size - 1]);
		print_sort(array, size, 0);
	}
	return (i + 1);
}



/**
 * print_sort - prints
 * @array: array
 * @size: size
 * @init: initialize
 * Return: 0
 */

void print_sort(int array[], size_t size, int init)
{
	static int *p = (void *)0;
	static size_t s;

	if (!p && init)
	{
		p = array;
		s = size;
	}
	if (!init)
		print_array(p, s);
}
