#include <stdio.h>

#define N 6

void bubbleSortDescending(int arr[N]) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[N] = {12, 34, 25, 66, 89, 1};

    bubbleSortDescending(arr);

    printf("Sorted array in descending order: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
