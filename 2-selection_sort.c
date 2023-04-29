#include "sort.h"

/**
 * swap - swaps two integers in an array
 * @a: first number
 * @b: second number
 */
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - sort array using the selection sort algorithm
 * @array: the array to be sorted
 * @size:size of the array
 */
void selection_sort(int *array, size_t size)
{
	unsigned int i, j, tmp_j = 0;
	int tmp;

	for (i = 0; i < size; i++)
	{
		tmp = array[i], tmp_j = i;
		for (j = i; j < size; j++)
		{
			if (array[j] < tmp)
				tmp = array[j], tmp_j = j;
		}
		if (array[i] != array[tmp_j])
		{
			swap(array + i, array + tmp_j);
			print_array(array, size);
		}
	}
}
