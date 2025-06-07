// Snippet 10: Generate All Subsets of a Set
void generate_subsets() {
    int n = 20;  // Number of elements in the set
    int *set = (int*) malloc(n * sizeof(int));

    // Generate all subsets (using bitmasking)
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                // Add set[i] to the current subset
            }
        }
    }

    free(set);
}