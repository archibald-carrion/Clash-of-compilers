#include <stdio.h>
#include <stdlib.h> // For malloc, free, rand, srand
#include <time.h>   // For time

// Snippet 181: Solving the Knapsack Problem using Branch and Bound
void knapsack_branch_bound() {
    int n = 1000;  // Number of items
    int W = 5000;  // Knapsack capacity
    int *weights = (int*) malloc(n * sizeof(int));
    int *values = (int*) malloc(n * sizeof(int));

    int **dp = (int**) malloc((n + 1) * sizeof(int*));
    for (int i = 0; i <= n; i++) {
        dp[i] = (int*) calloc((W + 1), sizeof(int)); // Use calloc to initialize to 0
    }

    srand(time(NULL)); // Initialize random seed
    // Initialize the weights and values
    for (int i = 0; i < n; i++) {
        weights[i] = rand() % 100 + 1;
        values[i] = rand() % 100 + 1;
    }

    // Implement Branch and Bound approach (simplified using DP table for bounding)
    // Fill dp array 
    // dp[i][w] stores the maximum value using the first i items with weight limit w
    // items are 0-indexed (weights[0]..weights[n-1]), so item 'i' is weights[i-1]
    for (int i = 1; i <= n; i++) { // Iterate over items
        for (int w = 1; w <= W; w++) { // Iterate over capacities
            if (weights[i - 1] <= w) { // If current item (i-1) can be included
                // Max of (not including item i-1, including item i-1)
                int value_if_included = values[i - 1] + dp[i - 1][w - weights[i - 1]];
                if (value_if_included > dp[i - 1][w]) {
                    dp[i][w] = value_if_included;
                } else {
                    dp[i][w] = dp[i - 1][w];
                }
            } else { // Current item cannot be included
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // Free memory
    for (int i = 0; i <= n; i++) {
        free(dp[i]);
    }
    free(dp);
    free(weights);
    free(values);
}

int main() {
    knapsack_branch_bound();
    return 0;
}
