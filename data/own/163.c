// Snippet 3: Solving Fibonacci Sequence with Dynamic Programming (Large N)
void fibonacci_dp() {
    int n = 1000000;  // Compute the Fibonacci sequence up to n-th term
    unsigned long long *fib = (unsigned long long*) malloc((n + 1) * sizeof(unsigned long long));

    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    free(fib);
}