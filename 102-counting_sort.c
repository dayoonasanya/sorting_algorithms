#include "sort.h"
#include <limits.h>
#include <stdlib.h>



/**
 * get_max - max
 *
 * @array: array
 * @size: size
 * Return: 0
 */


int get_max(int *array, size_t size)
{
	int max = INT_MIN;

	while (size--)
		if (array[size] > max)
			max = array[size];

	return (max);
}



/**
 * counting_sort - sort.
 * @array: array
 * @size: size.
 */


void counting_sort(int *array, size_t size)
{
	int *temp, *cpy, j, max;
	size_t i;

	if (!array || size < 2)
		return;

	max = get_max(array, size);
	temp = calloc(max + 1, sizeof(*temp));
	if (!temp)
		return;

	cpy = malloc(sizeof(*cpy) * size);
	if (!cpy)
	{
		free(temp);
		return;
	}

	for (i = 0; i < size; i++)
		temp[array[i]]++;

	for (j = 1; j < max + 1; j++)
		temp[j] += temp[j - 1];

	print_array(temp, max + 1);

	for (i = 0; i < size; i++)
	{
		temp[array[i]]--;
		cpy[temp[array[i]]] = array[i];
	}

	for (i = 0; i < size; i++)
		array[i] = cpy[i];

	free(temp);
	free(cpy);
}
