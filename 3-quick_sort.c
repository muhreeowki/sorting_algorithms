#include "sort.h"
#include <stddef.h>
#include <stdio.h>

/**
 * quick_sort - sorts an array of integers
 * in ascending order using the Quicj Sort algorithm
 *
 * @array - array to sort
 * @size - size of the array
 *
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
  partition(array, 0, size - 1, size);
}

/*
 * partition - divides an array into two sections along a pivot.
 * One section will contain numbers greater than the pivot,
 * the other section will contain numbers less than the pivot.
 *
 * @array - a pointer to an integer array
 * @low - the first number of the array to be partitioned
 * @high - the last number of the array to be partitioned
 *
 * Return - the index to which the pivot was moved to.
 */
void partition(int *array, int low, int high, int size)
{
  int j, i;
	int pivot;

	if ((low >= high) || (array == NULL))
		return;
	pivot = array[high];
	j = low;
	for (i = low; i < high; i++)
	{
		if (array[i] <= pivot)
		{
			if (j != i)
			{
				swap(array + j, array + i);
				print_array(array, size);
			}
			j++;
		}
	}
	if (j != high)
	{
		swap(array + j, array + high);
		print_array(array, size);
	}
	if (j - low > 1)
		partition(array, low, j - 1, size);
	if (high - j > 1)
		partition(array, j + 1, high, size);
}

/*
 * swap - Swaps the values of two pointers
 *
 * @ptr1 - a pointer to an integer
 * @ptr2 - a pointer to an integer
 *
 * Return - Nothing
 */
void swap(int *ptr1, int *ptr2)
{
  int temp;

  if (ptr1 && ptr2) 
  {
    temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
  }
}
