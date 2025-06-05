#include <stdio.h>

#define N 10

void printFibonacci() {
    int a = 0, b = 1;
    printf("Fibonacci Series: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", a);
        int next = a + b;
        a = b;
        b = next;
    }
    printf("\n");
}

int main() {
    printFibonacci();
    return 0;
}
