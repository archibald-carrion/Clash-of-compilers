#include <stdio.h>

int countWords(char str[]) {
    int count = 0;
    int inWord = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && !inWord) {
            count++;
            inWord = 1;
        } else if (str[i] == ' ') {
            inWord = 0;
        }
    }
    return count;
}

int main() {
    char str[] = "This is an example string.";
    printf("Number of words: %d\n", countWords(str));
    return 0;
}
