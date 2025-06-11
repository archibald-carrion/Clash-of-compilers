#include <stdio.h>

int sumOfNaturalNumbers(int n) {
    return (n * (n + 1)) / 2;
}

int main() {
    int n = 10;
    printf("Sum of first %d natural numbers: %d\n", n, sumOfNaturalNumbers(n));
    return 0;
}
