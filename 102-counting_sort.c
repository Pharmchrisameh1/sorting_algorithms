#include "sort.h"

/**
 * counting_sort - sorts an array using the counting sort algorithm.
 * @array: int pointer to the array being sorted.
 * @size: the size of the array being sorted.
 *
 * Return: void.
 */
void counting_sort(int *array, size_t size)
{
	int k = 0, i, *countarray, *sortedarray;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < (int)size; i++)
	{
		if (array[i] > k)
			k = array[i];
	}
	countarray = malloc(sizeof(int) * (k + 1));
	if (countarray == NULL)
		return;
	for (i = 0; i <= k; i++)
		countarray[i] = 0;
	/* counting the number of instances of elements */
	for (i = 0; i < (int)size; i++)
		countarray[array[i]]++;
	/* setting up the counting array */
	for (i = 0; i <= k; i++)
		countarray[i] += countarray[i - 1];
	print_array(countarray, k + 1);
	sortedarray = malloc(sizeof(int) * size);
	if (sortedarray == NULL)
	{
		free(countarray);
		return;
	}
	for (i = size - 1; i >= 0; i--)
	{
		countarray[array[i]]--;
		sortedarray[countarray[array[i]]] = array[i];
	}
	for (i = 0; i < (int)size; i++)
		array[i] = sortedarray[i];
	free(sortedarray);
	free(countarray);
}
