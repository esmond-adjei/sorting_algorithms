#include "sort.h"

/**
 *swap - swaps two integers.
 *@a: Pointer to the first integer.
 *@b: Pointer tothe second integer.
 */
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bubble_sort - sort integer array using bubble sort algorithm
 * @array: array of integer
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	if (array == NULL || size == 0)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
			}
		}
	}
}
