#include "sort.h"

/**
 * selection_sort - sorts an array of integers using
 * selection sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	/**
	 * pd: platform dancer
	 * cg: challenger
	 */
	size_t pd, cg;

	for (pd = 0; pd < size; pd++)
	{
		for (cg = pd + 1; cg < size; cg++)
		{
			if (array[pd] > array[cg])
			{
				int tmp = array[cg];

				array[cg] = array[pd];
				array[pd] = tmp;
			}
		}
	}
}
