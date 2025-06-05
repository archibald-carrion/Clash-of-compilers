#include <stdio.h>

int maxSubArraySum(int arr[], int size) {
    int maxSoFar = arr[0];
    int maxEndingHere = arr[0];

    for (int i = 1; i < size; i++) {
        maxEndingHere = maxEndingHere + arr[i] > arr[i] ? maxEndingHere + arr[i] : arr[i];
        maxSoFar = maxSoFar > maxEndingHere ? maxSoFar : maxEndingHere;
    }

    return maxSoFar;
}

int main() {
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Maximum subarray sum is: %d\n", maxSubArraySum(arr, size));
    return 0;
}
