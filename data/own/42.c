#include <stdio.h>

void decimalToBinary(int num) {
    if (num == 0) return;
    decimalToBinary(num / 2);
    printf("%d", num % 2);
}

int main() {
    int num = 13;
    printf("Binary of %d: ", num);
    decimalToBinary(num);
    printf("\n");
    return 0;
}
