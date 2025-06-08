// Snippet 2: Backtracking to find all subsets of a set
void backtrack(int *set, int *subset, int index, int size) {
    // Base case: print current subset
    if (index == size) {
        for (int i = 0; i < size; i++) {
            printf("%d ", subset[i]);
        }
        printf("\n");
        return;
    }

    // Include current element
    subset[index] = set[index];
    backtrack(set, subset, index + 1, size);

    // Exclude current element
    backtrack(set, subset, index + 1, size);
}

void generate_subsets_backtracking() {
    int n = 15;  // Set size
    int *set = (int*) malloc(n * sizeof(int));
    int *subset = (int*) malloc(n * sizeof(int));
    backtrack(set, subset, 0, n);

    free(subset);
    free(set);
}