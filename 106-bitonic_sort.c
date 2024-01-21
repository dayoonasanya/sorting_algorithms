#include "sort.h"


/**
 * merge - merge.
 * @array: array.
 * @size: size.
 * @start: start.
 * @seq: seq.
 * @flow: flow.
 */

void merge(int *array, size_t size, size_t start, size_t seq,
		char flow)
{
	size_t i, m = seq / 2;

	if (seq > 1)
	{
		for (i = start; i < start + m; i++)
		{
			if ((flow == UP && array[i] > array[i + m]) ||
			    (flow == DOWN && array[i] < array[i + m]))
				swap_func(array + i, array + i + m);
		}
		merge(array, size, start, m, flow);
		merge(array, size, start + m, m, flow);
	}
}


/**
 * bitonic - sequence.
 * @array: array.
 * @size: size.
 * @start: Starting sequence.
 * @seq: sequence.
 * @flow: dir.
 */

void bitonic(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t cut = seq / 2;
	char *str = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);

		bitonic(array, size, start, cut, UP);
		bitonic(array, size, start + cut, cut, DOWN);
		merge(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);
	}
}


/**
 * bitonic_sort -sort.
 * @array: array.
 * @size: size.
 */

void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic(array, size, 0, size, UP);
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
