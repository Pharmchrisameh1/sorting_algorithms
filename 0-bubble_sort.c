#include "sort.h"

/**
 * bubble_sort - this function sorts an array using the bubble
 * sort algorithm (in-place).
 * @array: int pointer to the array to be sorted.
 * @size: size of the array being sorted.
 */
void bubble_sort(int *array, size_t size)
{
	unsigned long int i, j;
	int temp, swapflag = 0;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < (size - 1); i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
				swapflag = 1;
			}
		}
		if (swapflag == 0)
			break;
	}
}
