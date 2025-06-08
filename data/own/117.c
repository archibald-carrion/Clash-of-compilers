#include <stdio.h>
#include <stdlib.h>
#include <math.h>

    // Snippet 7: Newton-Raphson method for finding roots
    void newton_raphson() {
        double x = 1.0, h = 1e-5, tolerance = 1e-6;
        int max_iter = 1000;
        
        for (int i = 0; i < max_iter; i++) {
            double f_x = x * x - 2.0;        // f(x) = x^2 - 2
            double f_prime = 2.0 * x;         // f'(x) = 2x
            
            double x_new = x - f_x / f_prime;
            
            if (fabs(x_new - x) < tolerance) {
                break;
            }
            
            x = x_new;
        }
    }

int main() {
    newton_raphson();
    return 0;
}
