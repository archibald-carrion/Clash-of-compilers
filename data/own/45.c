#include <stdio.h>

double squareRoot(double num) {
    double low = 0, high = num, mid;
    double epsilon = 0.0001;

    while ((high - low) > epsilon) {
        mid = (low + high) / 2;
        if (mid * mid > num) {
            high = mid;
        } else {
            low = mid;
        }
    }
    return (low + high) / 2;
}

int main() {
    double num = 16.0;
    printf("Square root of %.2f is: %.4f\n", num, squareRoot(num));
    return 0;
}
