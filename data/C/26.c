#include <stdio.h>

#define N 6

void bubbleSortOptimized(int arr[N]) {
    int swapped;
    for (int i = 0; i < N - 1; i++) {
        swapped = 0;
        for (int j = 0; j < N - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0) break;
    }
}

int main() {
    int arr[N] = {64, 34, 25, 12, 22, 11};

    bubbleSortOptimized(arr);

    printf("Sorted array: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
