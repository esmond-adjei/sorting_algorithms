#include "sort.h"

/**
 * swap - swaps two numbers.
 * @a: first number
 * @b: second number
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * partition - partitions the array and takes the last element as pivot
 * @arr: array to be partitioned
 * @first: first element index
 * @last: The last element index
 * @size: size of array
 * Return: integer
 */
int partition(int *arr, int first, int last, size_t size)
{
	int pivot;
	int i = (first);
	int j;

	pivot = arr[last];
	for (j = first; j < last; j++)
	{
		if (arr[j] <= pivot)
		{
			swap(&arr[i], &arr[j]);

			if (i != j)
				print_array(arr, size);

			i++;
		}
	}

	swap(&arr[i], &arr[last]);
	if (i != j)
	{
		print_array(arr, size);
	}
	return (i);
}

/**
 * quick_sort_array - quick_sort_array
 * @arr: arr
 * @first: first
 * @last: last
 * @size: size
 */
void quick_sort_array(int *arr, int first, int last, size_t size)
{
	int pivot;

	if (first < last)
	{
		pivot = partition(arr, first, last, size);
		quick_sort_array(arr, first, (pivot - 1), size);
		quick_sort_array(arr, (pivot + 1), last, size);
	}
}

/**
 * quick_sort - Sort an array using quick_sort algorithm
 * @array: array
 * @size: size
 **/
void quick_sort(int *array, size_t size)
{
	if (size < 2)
	{
		return;
	}
	quick_sort_array(array, 0, size - 1, size);
}
