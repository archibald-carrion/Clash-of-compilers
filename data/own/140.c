// Snippet 10: Count Occurrences of Characters in a String
void count_char_occurrences() {
    int n = 1000000;  // Number of operations
    char *str = (char*) malloc(n * sizeof(char));

    // Count characters
    int count[256] = {0};
    for (int i = 0; i < n; i++) {
        count[str[i]]++;
    }

    free(str);
}