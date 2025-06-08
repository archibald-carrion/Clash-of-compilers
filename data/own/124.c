#include <stdio.h>
#include <stdlib.h>

// Snippet 4: Binary Search (Iterative)
void binary_search() {
    int n = 1000;
    int *arr = (int*) malloc(n * sizeof(int));

    // Binary Search
    int target = 500;
    int left = 0;
    int right = n - 1;
    int found = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            found = 1;
            break;
        }
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    free(arr);
}

int main() {
    binary_search();
    return 0;
}