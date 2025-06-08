#include <stdlib.h>

// Snippet 1: Computing Pi using Monte Carlo method (with many iterations)
void monte_carlo_pi() {
    int n = 10000000;  // Number of points
    int count = 0;

    for (int i = 0; i < n; i++) {
        double x = (double) rand() / RAND_MAX;
        double y = (double) rand() / RAND_MAX;
        if (x * x + y * y <= 1) {
            count++;
        }
    }

    double pi = 4.0 * count / n;
}