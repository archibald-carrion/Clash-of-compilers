// Snippet 10: Count Occurrences of Characters in a String
#include <stdlib.h> // For malloc, free
#include <string.h> // For strlen (assuming str is populated)

void count_char_occurrences(int n, char target) {
    char *str = (char*) malloc(n * sizeof(char));

    // Count characters
    int count[256] = {0};
    for (int i = 0; i < n; i++) {
        count[str[i]]++;
    }

    free(str);
    // count array is not freed, but it's a local variable on the stack.
}

int main() {
    // Example usage
    // n should be the length of the string you'd allocate and fill.
    // For this example, let's assume a small string.
    count_char_occurrences(10, 'a'); 
    return 0;
}