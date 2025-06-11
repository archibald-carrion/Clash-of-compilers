#include <stdio.h>

int lcm(int a, int b) {
    int greater = (a > b) ? a : b;
    while (1) {
        if (greater % a == 0 && greater % b == 0)
            return greater;
        greater++;
    }
}

int main() {
    int a = 4, b = 6;
    printf("LCM of %d and %d is: %d\n", a, b, lcm(a, b));
    return 0;
}
