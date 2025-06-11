#include <stdio.h>

#define N 20

void generateFibonacci(int fib[N]) {
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < N; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
}

int main() {
    int fib[N];
    generateFibonacci(fib);

    printf("First %d Fibonacci numbers:\n", N);
    for (int i = 0; i < N; i++) {
        printf("%d ", fib[i]);
    }
    printf("\n");

    return 0;
}
