#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> // For UINT64_MAX
#include <time.h>   // For srand, time

// Snippet 191: Solving the Traveling Salesman Problem (TSP) using Dynamic Programming
void traveling_salesman_dp() {
    int n = 14;  // Number of cities
    int **dist = (int**) malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        dist[i] = (int*) malloc(n * sizeof(int));
    }

    // Simulate random distances
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = (i == j) ? 0 : rand() % 100 + 1;
        }
    }

    // DP table to store the results of subproblems
    unsigned long long **dp = (unsigned long long**) malloc((1 << n) * sizeof(unsigned long long*));
    for (int i = 0; i < (1 << n); i++) {
        dp[i] = (unsigned long long*) malloc(n * sizeof(unsigned long long));
    }

    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = UINT64_MAX;
        }
    }

    dp[1][0] = 0;  // Starting point

    // DP to find the minimum cost to visit all cities
    for (int mask = 1; mask < (1 << n); mask++) {
        for (int u = 0; u < n; u++) {
            if (mask & (1 << u)) {
                for (int v = 0; v < n; v++) {
                    if (!(mask & (1 << v))) {
                        dp[mask | (1 << v)][v] = (dp[mask | (1 << v)][v] > dp[mask][u] + dist[u][v]) ? dp[mask][u] + dist[u][v] : dp[mask | (1 << v)][v];
                    }
                }
            }
        }
    }

    unsigned long long ans = UINT64_MAX;
    for (int i = 1; i < n; i++) {
        ans = (ans > dp[(1 << n) - 1][i] + dist[i][0]) ? dp[(1 << n) - 1][i] + dist[i][0] : ans;
    }

    for (int i = 0; i < (1 << n); i++) {
        free(dp[i]);
    }
    free(dp);
    for (int i = 0; i < n; i++) {
        free(dist[i]);
    }
    free(dist);
}

int main() {
    srand(time(NULL));
    traveling_salesman_dp();
    return 0;
}
