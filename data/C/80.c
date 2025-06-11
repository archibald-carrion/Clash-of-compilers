#include <stdio.h>
#include <limits.h>

#define V 4

int min(int a, int b) {
    return (a < b) ? a : b;
}

int tsp(int dist[V][V], int mask, int pos, int dp[V][(1 << V) - 1]) {
    if (mask == (1 << V) - 1) {
        return dist[pos][0];
    }

    if (dp[pos][mask] != -1) {
        return dp[pos][mask];
    }

    int ans = INT_MAX;

    for (int city = 0; city < V; city++) {
        if ((mask & (1 << city)) == 0) {
            ans = min(ans, dist[pos][city] + tsp(dist, mask | (1 << city), city, dp));
        }
    }

    dp[pos][mask] = ans;
    return ans;
}

int main() {
    int dist[V][V] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    int dp[V][(1 << V) - 1];
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < (1 << V); j++) {
            dp[i][j] = -1;
        }
    }

    printf("Minimum cost of visiting all cities: %d\n", tsp(dist, 1, 0, dp));
    return 0;
}
