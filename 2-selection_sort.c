#include "sort.h"

/**
 * selction_sort - sorts an array of integers
 * in ascending order using the Selction Sort algorithm
 *
 * @array - array to sort
 * @size = size of the array
 *
 * Return: nothing
 */
void selection_sort(int *array, size_t size)
{
  size_t i, j;
  int lowest = 0, temp;

  if (size < 2)
    return;

  for (i = 0; i < size; i++)
  {
    lowest = i;
    for (j = i; j < size; j++)
    {
      if (array[j] < array[lowest])
        lowest = j;
    }
    temp = array[i];
    array[i] = array[lowest];
    array[lowest] = temp;
    print_array(array, size);
  }
}
