// Snippet 2: Sorting large array using Radix Sort
#include <stdlib.h> // For malloc, free, rand, srand
#include <time.h>   // For time

// A utility function to get maximum value in arr[]
int getMax(int arr[], int n) {
    int max_val = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }
    return max_val;
}

// A function to do counting sort of arr[] according to
// the digit represented by exp.
void counting_sort_radix(int arr[], int n, int exp) { // Renamed from counting_sort to avoid conflict
    int *output = (int*) malloc(n * sizeof(int));
    int *count = (int*) calloc(10, sizeof(int)); // Changed to calloc for clarity

    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    free(output);
    free(count); // Free the count array
}


void radix_sort(int n_elements) { // Renamed n to n_elements
    int *arr = (int*) malloc(n_elements * sizeof(int));
    srand(time(NULL));
    for(int i=0; i<n_elements; ++i) arr[i] = rand() % (n_elements * 100); // Larger range for radix sort

    if (n_elements <= 0) { // Handle empty or invalid size array
        free(arr);
        return;
    }

    int m = getMax(arr, n_elements);

    for (int exp = 1; m / exp > 0; exp *= 10)
        counting_sort_radix(arr, n_elements, exp);
    
    free(arr);
}

int main() {
    radix_sort(1000); // Example: sort an array of 1000 elements
    return 0;
}