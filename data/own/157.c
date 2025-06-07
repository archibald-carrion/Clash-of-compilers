// Snippet 7: Palindrome Check (with optimization)
int is_palindrome(char* str, int n) {
    for (int i = 0; i < n / 2; i++) {
        if (str[i] != str[n - 1 - i]) return 0;
    }
    return 1;
}

void palindrome_check() {
    char str[] = "aabbccddeeffgg";  // String to check
    int n = strlen(str);  // Length of the string

    is_palindrome(str, n);
}