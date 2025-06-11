#include <stdio.h>

#define MAX_CAPACITY 50
#define NUM_ITEMS 5

int knapSack(int W, int wt[], int val[], int n) {
    int dp[2][W + 1];

    for (int i = 0; i <= W; i++) {
        dp[0][i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (wt[i - 1] <= w)
                dp[i % 2][w] = (dp[(i - 1) % 2][w] > (val[i - 1] + dp[(i - 1) % 2][w - wt[i - 1]])) ? dp[(i - 1) % 2][w] : (val[i - 1] + dp[(i - 1) % 2][w - wt[i - 1]]);
            else
                dp[i % 2][w] = dp[(i - 1) % 2][w];
        }
    }
    return dp[n % 2][W];
}

int main() {
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    printf("Maximum value in knapsack = %d\n", knapSack(W, wt, val, n));
    return 0;
}
