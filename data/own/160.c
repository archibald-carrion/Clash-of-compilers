// Snippet 10: Generate all possible permutations of a string
void permute(char *str, int l, int r) {
    if (l == r) {
        printf("%s\n", str);
        return;
    }
    for (int i = l; i <= r; i++) {
        swap(&str[l], &str[i]);
        permute(str, l + 1, r);
        swap(&str[l], &str[i]);  // Backtrack
    }
}

void generate_permutations() {
    char str[] = "abcd";  // String to permute
    int n = strlen(str);
    permute(str, 0, n - 1);
}