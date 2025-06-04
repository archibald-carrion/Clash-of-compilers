#include <stdio.h>

int isPalindrome(char str[]) {
    int start = 0, end = 0;
    while (str[end] != '\0') end++;
    end--;
    while (start < end) {
        if (str[start] != str[end]) return 0;
        start++;
        end--;
    }
    return 1;
}

int main() {
    char str[] = "madam";
    if (isPalindrome(str)) {
        printf("\"%s\" is a palindrome.\n", str);
    } else {
        printf("\"%s\" is not a palindrome.\n", str);
    }
    return 0;
}
