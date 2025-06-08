// Snippet 4: Knapsack Problem using Dynamic Programming
#include <stdlib.h> // For malloc, free, calloc, rand, srand
#include <time.h>   // For time

int knapsack(int n_items, int W_capacity) { // Renamed n to n_items, W to W_capacity
    int *weights = (int*) malloc(n_items * sizeof(int));
    int *values = (int*) malloc(n_items * sizeof(int));
    
    // Initialize dp table with calloc (initializes to 0)
    int **dp = (int**) malloc((n_items + 1) * sizeof(int*));
    for (int i = 0; i <= n_items; i++) {
        dp[i] = (int*) calloc((W_capacity + 1), sizeof(int));
    }

    srand(time(NULL));
    for(int i=0; i<n_items; ++i) {
        weights[i] = rand() % 100 + 1; // Example weights
        values[i] = rand() % 100 + 1;  // Example values
    }


    for (int i = 1; i <= n_items; i++) {
        for (int w = 1; w <= W_capacity; w++) {
            if (weights[i-1] <= w) { // Item i-1 can be included
                int val_if_included = values[i-1] + dp[i-1][w - weights[i-1]];
                if (val_if_included > dp[i-1][w]) {
                    dp[i][w] = val_if_included;
                } else {
                    dp[i][w] = dp[i-1][w];
                }
            } else { // Item i-1 cannot be included
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    
    int result = dp[n_items][W_capacity];

    for (int i = 0; i <= n_items; i++) {
        free(dp[i]);
    }
    free(dp);
    free(weights);
    free(values);
    return result;
}

int main() {
    // Example usage
    knapsack(100, 500); // 100 items, capacity 500
    return 0;
}