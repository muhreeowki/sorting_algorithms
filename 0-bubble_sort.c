#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in
 * ascending order using the Bubble sort algorithm
 *
 * @array - array to sort
 * @size_t - size of the array
 *
 * Return: nothing
 */
void bubble_sort(int *array, size_t size)
{
  size_t i, j;
  int temp;


  for (j = 0; j < size; j++)
  {
    for (i = 0; i < size; i++) {
      if (i + 1 < size && array[i] > array[i+1])
      {
        temp = array[i];
        array[i] = array[i+1];
        array[i+1] = temp;
        print_array(array, size);
      }
    }
  }
}
