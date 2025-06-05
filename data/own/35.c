#include <stdio.h>

#define N 6

int findMax(int arr[N]) {
    int max = arr[0];
    for (int i = 1; i < N; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int arr[N] = {12, 34, 5, 78, 56, 89};
    printf("The maximum element in the array is: %d\n", findMax(arr));
    return 0;
}
