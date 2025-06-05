#include <stdio.h>

#define N 5
#define M 5

void mergeArrays(int arr1[], int arr2[], int result[]) {
    int i = 0, j = 0, k = 0;
    while (i < N && j < M) {
        if (arr1[i] < arr2[j]) {
            result[k++] = arr1[i++];
        } else {
            result[k++] = arr2[j++];
        }
    }
    while (i < N) result[k++] = arr1[i++];
    while (j < M) result[k++] = arr2[j++];
}

int main() {
    int arr1[N] = {1, 3, 5, 7, 9};
    int arr2[M] = {2, 4, 6, 8, 10};
    int result[N + M];

    mergeArrays(arr1, arr2, result);

    printf("Merged Array: ");
    for (int i = 0; i < N + M; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}
