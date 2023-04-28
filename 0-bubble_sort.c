#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * bubble_sort - sort integers in an array
 * @array[]: array of integers
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, tail;
	char is_sorted = 0;
	int num;

	if (size < 2)
		return;
 
	tail = size;
	while (!is_sorted)
	{
		is_sorted = 1;
		for (i = 0; i < tail - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				num = array[i];
				array[i] = array[i + 1];
				array[i + 1] = num;
				print_array(array, size);
				is_sorted = 0;
			}
		}
		tail--;
	}
}
