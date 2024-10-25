#include "sort.h"

/**
 * selection_sort - sorts an array using the selection sort algorithm.
 * @array: pointer to the array being sorted.
 * @size: size of the array being sorted.
 *
 * Return: void.
 */
void selection_sort(int *array, size_t size)
{
	int min, temp;
	size_t i, j, swaploc;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < (size - 1); i++)
	{
		min = array[i];
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < min)
			{
				min = array[j];
				swaploc = j;
			}
		}
		if (min == array[i])
			continue;
		temp = array[i];
		array[i] = array[swaploc];
		array[swaploc] = temp;
		print_array(array, size);
	}
}
