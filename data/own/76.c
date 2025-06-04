#include <stdio.h>

#define MAX 100

int memo[MAX];

int fibonacci(int n) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];
    memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return memo[n];
}

int main() {
    for (int i = 0; i < MAX; i++) {
        memo[i] = -1;
    }

    int n = 10;
    printf("Fibonacci number at position %d is: %d\n", n, fibonacci(n));
    return 0;
}
