# include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Snippet 3: Reverse a String in place
void reverse_string() {
    char str[] = "Hello, World!";
    int start = 0;
    int end = strlen(str) - 1;
    
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int main() {
    reverse_string();
    return 0;
}