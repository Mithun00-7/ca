#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

#define ARRAY_SIZE 25

void bubble_sort(int arr[], int n) {
    #pragma omp critical
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[ARRAY_SIZE];
    #pragma omp parallel for
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        arr[i] = rand() % 100;
    }
    printf("\nThe array elements are:\n");
    for (int i = 0; i < ARRAY_SIZE; i++)
        printf("%d  ", arr[i]);
    printf("\n");
    
    #pragma omp parallel shared(arr)
    {
        bubble_sort(arr, ARRAY_SIZE);
    }
    printf("Sorted array:\n");
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        printf("%d   ", arr[i]);
    }
    printf("\n");
    return 0;
}
