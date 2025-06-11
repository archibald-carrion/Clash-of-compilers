// Snippet 2: Backtracking to find all subsets of a set
#include <stdio.h>  // For printf
#include <stdlib.h> // For malloc, free

// Forward declaration if backtrack is used before definition in some compilers
void backtrack(int *set, int *subset, int k, int start, int n, int current_subset_size);

void print_subset(int *subset, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", subset[i]);
    }
    printf("\n");
}

// Backtracking function to find all subsets
void backtrack(int *set, int *subset, int k, int start, int n, int current_subset_size) {
    if (k == current_subset_size) { // If a subset of size k is found
        print_subset(subset, k);
        return;
    }
    if (start == n) { // Base case: if all elements are considered
        return;
    }

    // Include current element
    subset[current_subset_size] = set[start];
    backtrack(set, subset, k, start + 1, n, current_subset_size + 1);

    // Exclude current element (backtrack)
    backtrack(set, subset, k, start + 1, n, current_subset_size);
}


void generate_subsets_backtracking(int n_elements) { // Renamed n to n_elements to avoid conflict
    int *set = (int*) malloc(n_elements * sizeof(int));
    int *subset = (int*) malloc(n_elements * sizeof(int)); // Max possible subset size

    // Initialize set (e.g., 0, 1, 2, ..., n_elements-1)
    for (int i = 0; i < n_elements; i++) {
        set[i] = i;
    }

    printf("Subsets:\n");
    // To generate all subsets of all possible sizes from 0 to n_elements
    for (int k_size = 0; k_size <= n_elements; k_size++) { // Renamed k to k_size
         backtrack(set, subset, k_size, 0, n_elements, 0);
    }

    free(set);
    free(subset);
}

int main() {
    generate_subsets_backtracking(3); // Example: generate subsets for a set of 3 elements
    return 0;
}