#include "sort.h"



/**
 * heapify - heap.
 * @array: array.
 * @size: size.
 * @base: base.
 * @root: base.
 */

void heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, large;

	left = 2 * root + 1;
	right = 2 * root + 2;
	large = root;

	if (left < base && array[left] > array[large])
		large = left;
	if (right < base && array[right] > array[large])
		large = right;

	if (large != root)
	{
		swap_func(array + root, array + large);
		print_array(array, size);
		heapify(array, size, base, large);
	}
}


/**
 * heap_sort -sort.
 * @array: array.
 * @size: size
 */

void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		heapify(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		swap_func(array, array + i);
		print_array(array, size);
		heapify(array, size, i, 0);
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
