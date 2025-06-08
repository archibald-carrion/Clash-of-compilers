#include <stdio.h> // For printf

// Snippet 183: Compute the Greatest Common Divisor (GCD) using the Euclidean Algorithm
void euclidean_algorithm_gcd() {
    int a = 12345678, b = 87654321;

    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
}

int main() {
    euclidean_algorithm_gcd();

    // This file was initially empty.
    return 0;
}
