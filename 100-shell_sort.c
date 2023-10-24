#include "sort.h"

/*
 * shell_sort - sorts an array of integers in ascending orderusing
 * using the Shell sort algorithm, using the Knuth sequence
 *
 * @array - array to sort
 * @size - size of the array
 *
 * Return - Nothing
 */
void shell_sort(int *array, size_t size)
{
  size_t gap, j, i;
  int temp, swapped;

  gap = 1;
  while (gap < size) 
    gap = gap * 3 + 1;

  if (array == NULL || size <= 1)
    return;

  /* Using the Knuth sequence */
  for (; gap > 0; gap /= 3)
  {
    swapped = 0;
    for (i = gap;i < size; i++)
    {
      temp = array[i];
      for (j = i; j >= gap; j -= gap)
      {
        if (array[j - gap] > temp)
        {
          array[j] = array[j - gap];
          swapped = 1;
        }
        else {
        break;
        }
      }
      array[j] = temp;
    }
    if (swapped == 1)
      print_array(array, size);
  }
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
