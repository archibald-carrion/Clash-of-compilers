#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateRandomNumber(int low, int high) {
    return rand() % (high - low + 1) + low;
}

int main() {
    srand(time(0)); // Initialize random seed
    int low = 1, high = 100;
    printf("Random number between %d and %d: %d\n", low, high, generateRandomNumber(low, high));
    return 0;
}
