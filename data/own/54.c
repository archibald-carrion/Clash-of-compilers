#include <stdio.h>
#include  <math.h>

double geometricSum(double a, double r, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a * pow(r, i);
    }
    return sum;
}

int main() {
    double a = 1, r = 2;
    int n = 5;
    printf("Sum of geometric series: %.2f\n", geometricSum(a, r, n));
    return 0;
}
