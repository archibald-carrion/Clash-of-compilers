#include <stdio.h>
#include <stdlib.h>
#include <math.h>

    // Snippet 8: Bisection method for solving nonlinear equations
    void bisection() {
        double a = 0.0, b = 2.0, c, tolerance = 1e-6;
        int max_iter = 1000;
        
        for (int i = 0; i < max_iter; i++) {
            c = (a + b) / 2.0;
            
            if (fabs(b - a) < tolerance) {
                break;
            }
            
            if ((a * c) < 0) {
                b = c;
            } else {
                a = c;
            }
        }
    }

int main() {
    bisection();
    return 0;
}
