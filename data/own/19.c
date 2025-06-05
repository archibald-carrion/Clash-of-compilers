#include <stdio.h>

#define N 10

int findLargest(int arr[N]) {
    int largest = arr[0];
    for (int i = 1; i < N; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }
    return largest;
}

int main() {
    int arr[N] = {3, 2, 6, 9, 1, 5, 7, 8, 4, 0};
    printf("The largest element in the array is: %d\n", findLargest(arr));
    return 0;
}
