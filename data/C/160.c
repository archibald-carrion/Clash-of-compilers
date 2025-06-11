// Snippet 10: Generate all possible permutations of a string
#include <stdio.h>  // For printf
#include <string.h> // For strlen
#include <stdlib.h> // For malloc, free (if string was dynamically allocated)

// Utility function to swap two characters
void swap(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

// Function to print permutations of string
// This function takes three parameters:
// 1. String
// 2. Starting index of the string
// 3. Ending index of the string.
void permute(char *str, int l, int r) {
    if (l == r) {
        // printf("%s\n", str); // Printing can be slow for benchmarks
    } else {
        for (int i = l; i <= r; i++) {
            swap((str + l), (str + i));
            permute(str, l + 1, r);
            swap((str + l), (str + i)); // backtrack
        }
    }
}

void generate_permutations(char *str_param) { // Renamed str to str_param
    if (str_param == NULL) return;
    int n = strlen(str_param);
    permute(str_param, 0, n - 1);
}

int main() {
    char test_str[] = "ABC"; // Example string
    generate_permutations(test_str);
    // For benchmarking, a fixed longer string might be better, but permutations grow factorially.
    // char benchmark_str[] = "12345"; // Be careful with length
    // generate_permutations(benchmark_str);
    return 0;
}