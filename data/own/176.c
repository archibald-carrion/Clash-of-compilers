
// Snippet 6: Fibonacci Series Using Memoization
void fibonacci_memoization() {
    int n = 1000000;  // Calculate up to the n-th Fibonacci number
    long long *memo = (long long*) malloc((n + 1) * sizeof(long long));

    memo[0] = 0;
    memo[1] = 1;

    for (int i = 2; i <= n; i++) {
        memo[i] = memo[i - 1] + memo[i - 2];
    }

    free(memo);
}
