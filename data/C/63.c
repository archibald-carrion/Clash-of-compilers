#include <stdio.h>

#define N 3
#define W 50

int knapsack(int weights[], int values[], int n, int w) {
    int dp[n + 1][w + 1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= w; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (weights[i - 1] <= j)
                dp[i][j] = (values[i - 1] + dp[i - 1][j - weights[i - 1]] > dp[i - 1][j]) ?
                           (values[i - 1] + dp[i - 1][j - weights[i - 1]]) : dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][w];
}

int main() {
    int weights[] = {10, 20, 30};
    int values[] = {60, 100, 120};

    printf("Maximum value in knapsack: %d\n", knapsack(weights, values, N, W));
    return 0;
}
