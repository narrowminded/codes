#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printArray(int A[], int n){
    for(int i = 0; i < n; i++)
        printf("%d ",A[i]);
    printf("\n");
}

void Merge(int A[], int mid, int low, int high){
    int i, j, k, B[100];
    i = low; 
    j = mid+1; 
    k = low;

    while(i <= mid && j <= high){
        if(A[i] < A[j]){
            B[k] = A[i];
            k++;
            i++;
        }
        else{
            B[k] = A[j];
            k++;
            j++;
        }
    }
    while(i <= mid){
        B[k] = A[i];
        k++;
        i++;
    }
    while(j <= high){
        B[k] = A[j];
        k++;
        j++;
    }
    for(int i = low; i <= high; i++){
        A[i] = B[i];
    }
}

void MergeSort(int A[], int low, int high){
    if(low < high){
        int mid = (high+low)/2;
        MergeSort(A,low,mid);
        MergeSort(A,mid+1,high);
        Merge(A,mid,low,high);
    }
}

int main(){
    int A[] = {3, 5, 2, 13, 12, 9, 35, 45, 32, 11, 78, 24, 32, 89, 76, 12, 12, 90, 57};
    int n = sizeof(A) / sizeof(A[0]);
    printArray(A, n);
    MergeSort(A, 0, n-1);
    printArray(A, n);

    return 0;
}