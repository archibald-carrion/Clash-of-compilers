#include <limits.h>
#include <stdio.h>

#define N 3
#define V 11

int minCoins(int coins[], int m, int value) {
  int dp[value + 1];
  dp[0] = 0;

  for (int i = 1; i <= value; i++) {
    dp[i] = INT_MAX;
  }

  for (int i = 1; i <= value; i++) {
    for (int j = 0; j < m; j++) {
      if (coins[j] <= i) {
        int sub_res = dp[i - coins[j]];
        if (sub_res != INT_MAX && sub_res + 1 < dp[i]) {
          dp[i] = sub_res + 1;
        }
      }
    }
  }
  return (dp[value] == INT_MAX) ? -1 : dp[value];
}

int main() {
  int coins[] = { 1, 2, 5 };
  printf("Minimum coins required for change: %d\n", minCoins(coins, N, V));
  return 0;
}
