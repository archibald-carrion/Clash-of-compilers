// Snippet 3: Solving Fibonacci Sequence with Dynamic Programming (Large N)
#include <stdlib.h> // For malloc, free

unsigned long long fibonacci_dp(int n_val) { // Renamed n to n_val
    if (n_val < 0) return 0; // Or handle error
    unsigned long long *fib = (unsigned long long*) malloc((n_val + 1) * sizeof(unsigned long long));
    
    if (n_val >= 0) fib[0] = 0;
    if (n_val >= 1) fib[1] = 1;

    for (int i = 2; i <= n_val; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    
    unsigned long long result = 0;
    if (n_val >=0) result = fib[n_val]; // Store result before freeing
    free(fib);
    return result;
}

int main() {
    // Example usage
    fibonacci_dp(40); // Calculate Fibonacci(40)
    return 0;
}