#include "sort.h"
#include <stddef.h>

/**
 * quick_sort - sorts an array of integers
 * in ascending order using the Quick Sort algorithm
 *
 * @array - array to sort
 * @size - size of the array
 *
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
  my_quick_sort(array, 0, size, size);
}

void my_quick_sort(int *array, int low, int high, size_t size)
{
  int j;

  if (low < high)
  {
    j = partition(array, low, high, size);
    my_quick_sort(array, low, j, size);
    my_quick_sort(array, j + 1, high, size);
  }
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
int partition(int *array, int low, int high, int size)
{
  int i = low, j = high;
  int pivot = array[low];

  /* Two pointers will point at the opposite ends of the array */
  while(i < j)
  {
    /* 'i' will increment until it finds a number greater than the pivot */
    do {
      i++;
    }while (*(array + i) < pivot);

    /* 'j' will decrement until it finds a number less than the pivot */
    do {
      j--;
    }while (*(array + j) > pivot);

    /* we will swap the the two numbers if they are found */
    if (i < j)
    {
      swap((array + i), (array + j));
      print_array(array, size);
    }
  }
  /* if 'i' becomes greater than 'j' then the we move the pivot to position 'j'
   * then we return 'j'*/
  swap((array + low), (array + j));
  print_array(array, size);
  return j;
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

  temp = *ptr1;
  *ptr1 = *ptr2;
  *ptr2 = temp;
}
