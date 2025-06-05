#include <stdio.h>

#define N 6

int countOccurrences(int arr[N], int num) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] == num) {
            count++;
        }
    }
    return count;
}

int main() {
    int arr[N] = {1, 2, 3, 4, 2, 2};
    int num = 2;
    printf("Number of occurrences of %d: %d\n", num, countOccurrences(arr, num));
    return 0;
}
