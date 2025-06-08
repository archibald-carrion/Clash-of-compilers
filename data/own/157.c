// Snippet 7: Palindrome Check (with optimization)
#include <string.h> // For strlen
#include <stdio.h>  // For printf (example usage)
#include <stdbool.h> // For bool type

bool palindrome_check(const char *str_param) { // Renamed str to str_param to avoid conflict
    if (str_param == NULL) return false; // Handle NULL string
    int n = strlen(str_param);  // Length of the string
    for (int i = 0; i < n / 2; i++) {
        if (str_param[i] != str_param[n - 1 - i]) return false;
    }
    return true; // String is a palindrome
}

int main() {
    const char* test_str1 = "racecar";
    const char* test_str2 = "hello";
    // Example usage (optional, for testing)
    printf("%s is %s\n", test_str1, palindrome_check(test_str1) ? "a palindrome" : "not a palindrome");
    printf("%s is %s\n", test_str2, palindrome_check(test_str2) ? "a palindrome" : "not a palindrome");
    palindrome_check(test_str1); // Call to ensure it's benchmarked
    palindrome_check(test_str2);
    return 0;
}