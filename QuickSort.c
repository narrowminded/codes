#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int partition(int A[], int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (A[i] <= pivot)
        {
            i++;
        }

        while (A[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i < j);

    //Swap A[low] and A[j]
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;

    //Returning partitionIndex
    return j;
}

void QuickSort(int A[], int low, int high)
{
    int partitionIndex; // Index of pivot after partition
    if (low < high)
    {
        partitionIndex = partition(A, low, high);
        QuickSort(A, low, partitionIndex - 1);  // Sort Left Sub-Array
        QuickSort(A, partitionIndex + 1, high); // Sort Right Sub-Array
    }
}

int main()
{
    int A[] = {3, 5, 2, 13, 12,9,35,45,32,11,78,24,32,89,76,12,12,90,57};
    int n = sizeof(A)/sizeof(A[0]);
    printArray(A, n);
    QuickSort(A, 0, n - 1);
    printArray(A, n);

    return 0;
}