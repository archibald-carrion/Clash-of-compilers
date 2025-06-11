#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a number is prime moved to global scope
int is_prime(int num) {
    if (num <= 1) return 0;
    if (num == 2) return 1;
    if (num % 2 == 0) return 0;
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return 0;
    }
    return 1;
}

// Efficient prime check using Sieve of Eratosthenes
void prime_check() {
    int limit = 100000;  // Reduced from 1000000 to avoid excessive computation
    
    // Allocate memory for sieve
    char *sieve = (char*) malloc((limit + 1) * sizeof(char));
    if (!sieve) {
        perror("Failed to allocate memory for sieve");
        return;
    }
    
    // Initialize sieve: 1 means potentially prime, 0 means definitely not prime
    memset(sieve, 1, (limit + 1) * sizeof(char));
    
    // 0 and 1 are not prime
    sieve[0] = sieve[1] = 0;
    
    // Apply Sieve of Eratosthenes
    for (int i = 2; i * i <= limit; i++) {
        if (sieve[i]) {
            // Mark all multiples of i as non-prime
            for (int j = i * i; j <= limit; j += i) {
                sieve[j] = 0;
            }
        }
    }
    
    // Count the number of primes (optional)
    int count = 0;
    for (int i = 2; i <= limit; i++) {
        if (sieve[i]) {
            count++;
        }
    }
    
    // Print the result (optional)
    printf("Found %d prime numbers up to %d\n", count, limit);
    
    free(sieve);
}

int main() {
    prime_check();
    return 0;
}