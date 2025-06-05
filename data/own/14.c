#include <stdio.h>

#define N 10

int sumOfSquares() {
    int sum = 0;
    for (int i = 1; i <= N; i++) {
        sum += i * i;
    }
    return sum;
}

int main() {
    int result = sumOfSquares();
    printf("The sum of squares of the first %d numbers is: %d\n", N, result);
    return 0;
}
