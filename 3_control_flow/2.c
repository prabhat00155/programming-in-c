/* Program to implement a function that takes an array of integers as an
 * argument and sorts the array.
 * Author: Prabhat Roy
 */

#include <stdio.h>

#define SIZE 10

void sort(int []);

int main()
{
    int arr[SIZE] = { 50, 50, 60, -100, 10, -20, 0, 100, 1000, 35 };
    int i;
    sort(arr);
    printf("Sorted array:\n");
    for (i = 0; i < SIZE; i++)
        printf("%d\t", arr[i]);
    printf("\n");
    return 0;
}

void sort(int arr[])
{
    int i, j, min, tmp;
    for (i = 0; i < SIZE - 1; i++) {
        min = i;
        /* Find the minimum value from element i to the end */
        for (j = i + 1; j < SIZE; j++)
            if (arr[j] < arr[min])
               min = j;
        /* Move the minimum value to element i */
        tmp = arr[min];
        arr[min] = arr[i];
        arr[i] = tmp;
    }
}
