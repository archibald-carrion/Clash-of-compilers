// Snippet 2: Prime Number Check (Efficient approach with large numbers)
void prime_check() {
    int limit = 1000000;  // Upper limit to check primes
    
    int is_prime(int num) {
        if (num <= 1) return 0;
        if (num == 2) return 1;
        if (num % 2 == 0) return 0;
        for (int i = 3; i * i <= num; i += 2) {
            if (num % i == 0) return 0;
        }
        return 1;
    }

    for (int i = 2; i <= limit; i++) {
        is_prime(i);  // Prime check
    }
}