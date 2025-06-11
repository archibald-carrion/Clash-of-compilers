#include <stdio.h>

#define N 5

void reverseArray(int arr[N]) {
    int start = 0, end = N - 1;
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main() {
    int arr[N] = {1, 2, 3, 4, 5};
    reverseArray(arr);

    printf("Reversed array: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
