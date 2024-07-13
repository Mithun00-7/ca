#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#define ARRAY_SIZE 25

void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        #pragma omp parallel for shared(arr)
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

    bubble_sort(arr, ARRAY_SIZE);

    printf("Sorted array:\n");
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        printf("%d  ", arr[i]);
    }
    printf("\n");
    return 0;
}
