#include "sort.h"


/**
 * create_partition - creates a partition (Lomuto) to
 * be quick sorted.
 * @array: int pointer to the array to be partitioned.
 * @begin: beginning of the array to be partitioned.
 * @end: ending of the array to be partitioned.
 * @size: the size of the whole list.
 *
 * Return: sorted pivot index.
 */
int create_partition(int *array, int begin, int end, int size)
{
	int pivot, i, temp, pivotindex;

	pivot = array[end];
	pivotindex = begin - 1;

	for (i = begin; i < end; i++)
	{
		if (array[i] <= pivot)
		{
			pivotindex++;
			temp = array[i];
			array[i] = array[pivotindex];
			array[pivotindex] = temp;
			if (array[i] != array[pivotindex])
				print_array(array, size);
		}
	}
	pivotindex++;
	temp = array[end];
	array[end] = array[pivotindex];
	array[pivotindex] = temp;
	if (array[end] != array[pivotindex])
		print_array(array, size);
	return (pivotindex);
}

/**
 * sort - a recursive function that sorts the list
 * using the quick sort algorithm.
 * @array: int pointer to the array to be sorted.
 * @begin: beginning of the array to be sorted.
 * @end: ending of the array to be sorted.
 * @size: size of the whole list.
 *
 * Return: void.
 */
void sort(int *array, int begin, int end, int size)
{
	int splitloc;

	if (begin >= end || begin < 0)
		return;

	splitloc = create_partition(array, begin, end, size);

	/* Sort the left side after splitting */
	sort(array, 0, splitloc - 1, size);

	/* Sort the right side after splitting */
	sort(array, splitloc + 1, end, size);
}

/**
 * quick_sort - this function sorts an array using the
 * quick sort algorithm.
 * @array: int pointer to the array to be sorted.
 * @size: the size of the array to be sorted.
 *
 * Return: void.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	sort(array, 0, size - 1, size);
}
