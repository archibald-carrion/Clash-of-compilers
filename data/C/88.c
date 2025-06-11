#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isPalindrome(char* str, int start, int end) {
    while (start < end) {
        if (str[start] != str[end]) return false;
        start++;
        end--;
    }
    return true;
}

int minPalindromes(char* str, int n) {
    int dp[n+1];
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        dp[i] = i;
        for (int j = 0; j < i; j++) {
            if (isPalindrome(str, j, i-1)) {
                dp[i] = (dp[i] < dp[j] + 1) ? dp[i] : dp[j] + 1;
            }
        }
    }
    return dp[n];
}

int main() {
    char str[] = "aab";
    int n = strlen(str);
    printf("Minimum palindrome partitions: %d\n", minPalindromes(str, n));
    return 0;
}
