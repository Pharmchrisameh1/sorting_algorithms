#include "sort.h"

/**
 * swap - swaps two location in a list.
 * @array: int pointer to the array.
 * @a: first location of array to be swapped.
 * @b: second location of array to be swapped.
 *
 * Return: returns void.
 */
void swap(int a, int b, int *array)
{
	int temp;

	temp = array[a];
	array[a] = array[b];
	array[b] = temp;
}

/**
 * shell_sort - sorts a list using the shell sort algorithm
 * using a Knuth squence gap.
 * @array: int pointer to the array to be sorted.
 * @size: the size of the array to be sorted.
 *
 * Return: void.
 */
void shell_sort(int *array, size_t size)
{
	int maxgap = 1, i, j, k;

	if (array == NULL || size < 2)
		return;
	while ((maxgap * 3 + 1) <= (int)size - 1)
		maxgap = (maxgap * 3) + 1;
	/* Maxgap intervals done through Knuth sequence */
	for (; maxgap > 0; maxgap = (maxgap - 1) / 3)
	{
		for (i = 0; i + maxgap < (int)size; i++)
		{
			if (array[i] > array[i + maxgap])
			{
				/* Swap the forward element */
				swap(i, i + maxgap, array);
				/* Check for backward elements */
				for (k = i, j = i - maxgap; j >= 0; j -= maxgap, k -= maxgap)
				{
					/* Swap backward elements */
					if (array[k] < array[j])
						swap(k, j, array);
					else
						break;
				}
			}
		}
		print_array(array, size);
	}
}
