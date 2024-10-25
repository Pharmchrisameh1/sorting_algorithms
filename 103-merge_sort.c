#include "sort.h"

/**
 * merge - merge sorts 2 sorted lists.
 * @lo: lowerbound of the array.
 * @hi: higher bound of the array.
 * @middle: middle of the array.
 * @array: original non-sorted array.
 * @sortedarray: sorted array.
 *
 * Return: void.
 */
void merge(int lo, int hi, int middle, int *array, int *sortedarray)
{
	int i = lo, j = middle, sort_place, temp;

	printf("Merging...\n[left]:");
	for (temp = lo; temp < middle; temp++)
	{
		printf(" %d", array[temp]);
		if (temp != (middle - 1))
			printf(",");
	}
	printf("\n[right]:");
	for (temp = middle; temp < hi; temp++)
	{
		printf(" %d", array[temp]);
		if (temp != (hi - 1))
			printf(",");
	}
	printf("\n");
	for (sort_place = lo; i < middle && j < hi; sort_place++)
	{
		if (array[i] < array[j])
			sortedarray[sort_place] = array[i++];
		else
			sortedarray[sort_place] = array[j++];
	}
	for (; i < middle; i++)
		sortedarray[sort_place++] = array[i];
	for (; j < hi; j++)
		sortedarray[sort_place++] = array[j];
	printf("[Done]:");
	for (temp = lo; temp < hi; temp++)
	{
		printf(" %d", sortedarray[temp]);
		if (temp != (hi - 1))
			printf(",");
	}
	printf("\n");
	for (i = lo; i < hi; i++)
		array[i] = sortedarray[i];
}

/**
 * split_merge - recursive function that keeps splitting
 * an array and then finally merging every 2 halves together.
 * @array: the array to be sorted.
 * @sortedarray: the resulting sorted array.
 * @lo: lowerbound of the array.
 * @hi: higher bound of the array.
 *
 * Return: void.
 */
void split_merge(int *array, int *sortedarray, int lo, int hi)
{
	int middle;

	/* Recursion basecase */
	if (hi - lo <= 1)
		return;

	middle = (lo + hi) / 2;

	/* Split left side further */
	split_merge(array, sortedarray, lo, middle);
	/* Split right side further */
	split_merge(array, sortedarray, middle, hi);
	merge(lo, hi, middle, array, sortedarray);
}

/**
 * merge_sort - sorts an array using the merge sort algorithm.
 * @array: int pointer to the array being sorted.
 * @size: size of the array being sorted.
 *
 * Return: void.
 */
void merge_sort(int *array, size_t size)
{
	int *sortedarray, i;

	if (array == NULL || size < 2)
		return;
	sortedarray = malloc(sizeof(int) * size);
	if (sortedarray == NULL)
		return;
	for (i = 0; i < (int)size; i++)
		sortedarray[i] = array[i];
	split_merge(array, sortedarray, 0, size);
	for (i = 0; i < (int)size; i++)
		array[i] = sortedarray[i];
	free(sortedarray);
}
