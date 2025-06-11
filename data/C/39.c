#include <stdio.h>

#define N 5

void countFrequency(int arr[N]) {
    int frequency[10] = {0};
    for (int i = 0; i < N; i++) {
        frequency[arr[i]]++;
    }

    printf("Frequency of elements:\n");
    for (int i = 0; i < 10; i++) {
        if (frequency[i] != 0) {
            printf("%d occurs %d times\n", i, frequency[i]);
        }
    }
}

int main() {
    int arr[N] = {1, 2, 2, 3, 3};
    countFrequency(arr);
    return 0;
}
