#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int array[] = {27, 14, 4, 21, 2, 20, 8, 24, 3, 5, 19, 11,
		15, 29, 28, 25, 18, 17, 30, 16};
	size_t n = sizeof(array) / sizeof(array[0]);

	print_array(array, n);
	printf("\n");
	selection_sort(array, n);
	printf("\n");
	print_array(array, n);
	return (0);
}
