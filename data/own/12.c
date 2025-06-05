#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

void generateArray(int arr[N]) {
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % 100;
    }
}

void sortArray(int arr[N]) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int binarySearch(int arr[N], int x) {
    int low = 0, high = N - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == x) return mid;
        if (arr[mid] < x) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main() {
    srand(time(0));
    int arr[N];
    generateArray(arr);

    printf("Generated Array:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    sortArray(arr);

    int x = arr[rand() % N];
    printf("Value to search: %d\n", x);

    int result = binarySearch(arr, x);
    if (result != -1) {
        printf("Value found at index: %d\n", result);
    } else {
        printf("Value not found.\n");
    }

    return 0;
}
