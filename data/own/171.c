#include <stdio.h> // For printf

// Snippet 10: Finding the Greatest Common Divisor (GCD) Using Euclidean Algorithm
void gcd_euclidean(int a_val, int b_val) { // Renamed a, b
    int temp;
    // Ensure a_val >= b_val, if not, swap them (not strictly necessary for Euclidean but common)
    // However, the loop handles it correctly even if a_val < b_val initially.
    while (b_val != 0) {
        temp = b_val;
        b_val = a_val % b_val;
        a_val = temp;
    }
    // printf("GCD: %d\n", a_val); // Printing can be slow for benchmarks
}

int main() {
    gcd_euclidean(1071, 462); // Example
    gcd_euclidean(98, 56);
    return 0;
}
