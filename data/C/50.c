#include <stdio.h>

#define N 6

int findMin(int arr[N]) {
    int min = arr[0];
    for (int i = 1; i < N; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int main() {
    int arr[N] = {12, 34, 5, 78, 56, 89};
    printf("The minimum element in the array is: %d\n", findMin(arr));
    return 0;
}
