#include <stdio.h>

int sumOfDigits(int num) {
    int sum = 0;
    while (num != 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main() {
    int num = 12345;
    printf("Sum of digits of %d is: %d\n", num, sumOfDigits(num));
    return 0;
}
