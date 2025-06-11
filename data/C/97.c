#include <stdio.h>

#define MAX 100

int longestIncreasingSubsequence(int arr[], int n) {
    int lis[n];
    for (int i = 0; i < n; i++) {
        lis[i] = 1;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
            }
        }
    }

    int maxLis = 0;
    for (int i = 0; i < n; i++) {
        if (lis[i] > maxLis) {
            maxLis = lis[i];
        }
    }
    return maxLis;
}

int main() {
    int arr[] = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Length of Longest Increasing Subsequence: %d\n", longestIncreasingSubsequence(arr, size));
    return 0;
}
