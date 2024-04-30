#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order
 *              using the Quick sort algorithm
 *
 * @array: Pointer to the array to be sorted
 * @size: Number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    /* Call the helper function to perform Quick sort */
    quick_sort_recursive(array, 0, size - 1);
}

/**
 * quick_sort_recursive - Helper function to perform Quick sort recursively
 *
 * @array: Pointer to the array to be sorted
 * @low: Index of the low element of the partition
 * @high: Index of the high element of the partition
 */
void quick_sort_recursive(int *array, int low, int high)
{
    if (low < high)
    {
        int pivot = partition(array, low, high);
        quick_sort_recursive(array, low, pivot - 1);
        quick_sort_recursive(array, pivot + 1, high);
    }
}

/**
 * partition - Partition the array and return the index of the pivot
 *
 * @array: Pointer to the array to be sorted
 * @low: Index of the low element of the partition
 * @high: Index of the high element of the partition
 *
 * Return: Index of the pivot element
 */
int partition(int *array, int low, int high)
{
    int pivot = array[high];
    int i = low - 1;
    int j;

    for (j = low; j < high; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            swap(&array[i], &array[j]);
            print_array(array, high - low + 1);
        }
    }
    swap(&array[i + 1], &array[high]);
    print_array(array, high - low + 1);
    return (i + 1);
}

/**
 * swap - Swaps two integers
 *
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

