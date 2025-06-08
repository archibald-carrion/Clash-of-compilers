#include <stdio.h>
#include <stdlib.h>
// Snippet 5: Fibonacci Sequence (Iterative)
void fibonacci_iterative() {
    int n = 1000000;  // Calculate the first n Fibonacci numbers
    unsigned long long *fib = (unsigned long long*) malloc(n * sizeof(unsigned long long));

    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    free(fib);
}

int main() {
    fibonacci_iterative();
    return 0;
}