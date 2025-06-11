#include <stdio.h>

int reverseNumber(int num) {
    int reversed = 0;
    while (num != 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    return reversed;
}

int main() {
    int num = 12345;
    printf("Reversed number: %d\n", reverseNumber(num));
    return 0;
}
