#include <stdlib.h> // For malloc, free
#include <string.h> // For memset

// Snippet 6: Fibonacci Series Using Memoization
long long fib_memo_recursive(int n_val, long long *memo) { // Renamed n to n_val
    if (memo[n_val] != -1) return memo[n_val];
    if (n_val <= 1) return n_val;
    memo[n_val] = fib_memo_recursive(n_val - 1, memo) + fib_memo_recursive(n_val - 2, memo);
    return memo[n_val];
}

long long fibonacci_memoization(int n_val) { // Renamed n to n_val
    if (n_val < 0) return 0; // Or handle error
    long long *memo = (long long*) malloc((n_val + 1) * sizeof(long long));
    // Initialize memo array with -1 (or another indicator for not computed)
    for (int i = 0; i <= n_val; i++) {
        memo[i] = -1; 
    }
    // Or use memset: memset(memo, -1, (n_val + 1) * sizeof(long long));
    // Note: memset works byte-wise, so -1 works for char types or if all bytes of -1 represent the desired value.
    // For long long, a loop is safer for initializing to -1 unless you are sure about its byte representation.
    // For this case, loop is fine.

    long long result = fib_memo_recursive(n_val, memo);
    free(memo);
    return result;
}

int main() {
    fibonacci_memoization(40); // Calculate Fibonacci(40)
    return 0;
}
