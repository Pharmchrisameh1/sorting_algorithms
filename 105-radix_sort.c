#include "sort.h"


/**
 * free_radixtable - the function frees a radixtable.
 * @radixtable: the radix table to be freed.
 *
 * Return: void.
 */
void free_radixtable(numnode **radixtable)
{
	numnode *cursor1, *cursor2;
	int i;

	for (i = 0; i < 10; i++)
	{
		cursor1 = radixtable[i];
		while (cursor1)
		{
			cursor2 = cursor1->next;
			if (cursor1 != NULL)
				free(cursor1);
			cursor1 = cursor2;
		}
		radixtable[i] = NULL;
	}
}

/**
 * addtobin - the function adds the number to its corresponding place
 * in the bins table (according to the digit).
 * @radixtable: the radix array used.
 * @index: the index to where the number will be added.
 * @number: the value being added to the table.
 *
 * Return: void.
 */
void addtobin(numnode *radixtable[], int index, int number)
{
	numnode *new, *cursor;

	new = malloc(sizeof(numnode));
	if (new == NULL)
	{
		free_radixtable(radixtable);
		return;
	}
	new->n = number;
	new->next = NULL;
	cursor = radixtable[index];
	if (cursor)
	{
		while (cursor->next != NULL)
			cursor = cursor->next;
		cursor->next = new;
	}
	else
		radixtable[index] = new;
}

/**
 * radix_sort - the function sorts an array of positive integers in ascending order
 * using the radix sort algorithm.
 * @array: the array being sorted.
 * @size: the size of the array being sorted.
 *
 * Return: void.
 */
void radix_sort(int *array, size_t size)
{
	int i, j, k, l, passnum = 0, maxnum, digit, divisor = 1;
	numnode *radixtable[10] = {NULL}, *cursor;

	if (array == NULL || size < 2)
		return;
	for (i = 0, maxnum = array[0]; i < (int)size; i++)
		maxnum = array[i] > maxnum ? array[i] : maxnum;
	for (; maxnum; maxnum /= 10)
		passnum++;
	for (i = 0; i < passnum; i++, divisor *= 10)
	{
		for (j = 0; j < (int)size; j++)
		{
			digit = (array[j] / divisor) % 10;
			addtobin(radixtable, digit, array[j]);
		}
		for (k = 0, l = 0; k < 10; k++)
		{
			for (cursor = radixtable[k]; cursor; cursor = cursor->next)
				array[l++] = cursor->n;
		}
		print_array(array, size);
		free_radixtable(radixtable);
	}
}
