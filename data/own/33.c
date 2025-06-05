#include <stdio.h>

#define N 5

void rotateArray(int arr[], int n) {
    int temp[n];
    for (int i = 0; i < n; i++) {
        temp[i] = arr[i];
    }
    for (int i = 0; i < N - n; i++) {
        arr[i] = arr[i + n];
    }
    for (int i = 0; i < n; i++) {
        arr[N - n + i] = temp[i];
    }
}

int main() {
    int arr[N] = {1, 2, 3, 4, 5};
    int n = 2;

    rotateArray(arr, n);

    printf("Array after rotating by %d positions: ", n);
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
