#include <stdio.h>

#define N 5

int sumArray(int arr[N]) {
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int arr[N] = {1, 2, 3, 4, 5};
    printf("Sum of array elements: %d\n", sumArray(arr));
    return 0;
}
