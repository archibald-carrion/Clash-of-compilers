// Snippet 5: Sieve of Eratosthenes (Finding Primes up to a Large Number)
#include <stdlib.h> // For malloc, free
#include <string.h> // For memset (alternative to loop for initialization)

void sieve_of_eratosthenes(int n) {
    int *sieve = (int*) malloc((n + 1) * sizeof(int));
    for (int i = 0; i <= n; i++) sieve[i] = 1;  // Assume all numbers are prime

    sieve[0] = sieve[1] = 0;  // 0 and 1 are not prime
    for (int i = 2; i * i <= n; i++) {
        if (sieve[i] == 1) {
            for (int j = i * i; j <= n; j += i) {
                sieve[j] = 0;
            }
        }
    }

    // Free memory
    free(sieve);
}

int main() {
    // Example usage
    sieve_of_eratosthenes(100); // Find primes up to 100
    return 0;
}