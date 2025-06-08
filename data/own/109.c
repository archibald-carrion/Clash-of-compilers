#include <stdio.h>

int merge(int arr[], int temp[], int left, int mid, int right);

int mergeAndCount(int arr[], int temp[], int left, int right) {
    if (left == right) return 0;
    int mid = (left + right) / 2;
    int invCount = 0;

    invCount += mergeAndCount(arr, temp, left, mid);
    invCount += mergeAndCount(arr, temp, mid + 1, right);

    invCount += merge(arr, temp, left, mid, right);

    return invCount;
}

int merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left; 
    int j = mid + 1; 
    int k = left; 
    int invCount = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            invCount += (mid-i + 1);
        }
    }

    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    for (i = left; i <= right; i++) arr[i] = temp[i];

    return invCount;
}

int main() {
    int arr[] = {1, 20, 6, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int temp[n];
    printf("Number of inversions are: %d\n", mergeAndCount(arr, temp, 0, n - 1));
    return 0;
}
