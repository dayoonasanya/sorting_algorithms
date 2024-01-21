#include <stdio.h>
#include "sort.h"


/**
 * swap_func - Function that swaps two values
 *
 * @a: Fisrt value
 * @b: Second value
 * Return: 0
 */


void swap_func(int *a, int *b)
{
	int tmp;

	tmp = *b;
	*b = *a;
	*a = tmp;
}
