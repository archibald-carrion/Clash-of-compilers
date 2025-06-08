#include <stdio.h>
#include <stdlib.h> // For general utilities, though not strictly needed for this snippet
#include <time.h>   // For time, srand if used

// Snippet 200: Counting the Number of Set Bits in an Integer (Brian Kernighan's Algorithm)
void count_set_bits_bk() {
    int n = 1000000;  // Number of integers to check
    long long total_set_bits = 0; // Use long long for potentially large sum

    for (int i = 0; i < n; i++) {
        int num = i;
        int current_num_set_bits = 0;
        while (num) {
            num = num & (num - 1);  // Brian Kernighan's algorithm
            current_num_set_bits++;
        }
        total_set_bits += current_num_set_bits;
    }
    // Removed printf statement
}

int main() {
    count_set_bits_bk();
    return 0;
}
