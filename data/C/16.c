#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void sieveOfEratosthenes() {
    int primes[MAX];
    for (int i = 0; i < MAX; i++) {
        primes[i] = 1;
    }
    primes[0] = primes[1] = 0;

    for (int i = 2; i * i <= MAX; i++) {
        if (primes[i]) {
            for (int j = i * i; j <= MAX; j += i) {
                primes[j] = 0;
            }
        }
    }

    printf("Prime numbers up to %d:\n", MAX);
    for (int i = 2; i < MAX; i++) {
        if (primes[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    sieveOfEratosthenes();
    return 0;
}
