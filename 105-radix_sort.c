#include "sort.h"
#include <stdlib.h>


/**
 * max_max - max.
 * @array: array.
 * @size: size.
 * Return: max.
 */

int max_max(int *array, int size)
{
	int max, i;

	for (max = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}


/**
 * counting - count.
 * @array: array.
 * @size: size.
 * @sig: sig.
 * @buff: buffer.
 */

void counting(int *array, size_t size, int sig, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / sig) % 10] += 1;

	for (i = 0; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		buff[count[(array[i] / sig) % 10] - 1] = array[i];
		count[(array[i] / sig) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = buff[i];
}


/**
 * radix_sort -sort.
 * @array: array.
 * @size: size.
 */

void radix_sort(int *array, size_t size)
{
	int max, sig, *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	max = max_max(array, size);
	for (sig = 1; max / sig > 0; sig *= 10)
	{
		counting(array, size, sig, buff);
		print_array(array, size);
	}

	free(buff);
}
