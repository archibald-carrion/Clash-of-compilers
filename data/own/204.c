#include <stdio.h>
#include <stdlib.h>
#include <math.h> // For M_PI, cos, sin
#include <time.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Helper function for fft_signal_processing, moved to file scope
static void s194_fft_recursive(double *real, double *imag, int n) {
    if (n <= 1) return;
    int mid = n / 2;
    double *even_real = (double*) malloc(mid * sizeof(double));
    double *even_imag = (double*) malloc(mid * sizeof(double));
    double *odd_real = (double*) malloc(mid * sizeof(double));
    double *odd_imag = (double*) malloc(mid * sizeof(double));

    for (int i = 0; i < mid; i++) {
        even_real[i] = real[2 * i];
        even_imag[i] = imag[2 * i];
        odd_real[i] = real[2 * i + 1];
        odd_imag[i] = imag[2 * i + 1];
    }

    s194_fft_recursive(even_real, even_imag, mid);
    s194_fft_recursive(odd_real, odd_imag, mid);

    for (int i = 0; i < mid; i++) {
        double cos_val = cos(2 * M_PI * i / n);
        double sin_val = sin(2 * M_PI * i / n);
        double t_real = cos_val * odd_real[i] - sin_val * odd_imag[i];
        double t_imag = sin_val * odd_real[i] + cos_val * odd_imag[i];

        real[i] = even_real[i] + t_real;
        imag[i] = even_imag[i] + t_imag;
        real[i + mid] = even_real[i] - t_real;
        imag[i + mid] = even_imag[i] - t_imag;
    }

    free(even_real);
    free(even_imag);
    free(odd_real);
    free(odd_imag);
}

// Snippet 194: FFT (Fast Fourier Transform) for Signal Processing
void fft_signal_processing() {
    int n = 1024;  // Signal length (must be a power of 2)
    double *real = (double*) malloc(n * sizeof(double));
    double *imag = (double*) malloc(n * sizeof(double));

    // Initialize the real and imaginary parts with values
    for (int i = 0; i < n; i++) {
        real[i] = cos(2 * M_PI * i / n);
        imag[i] = sin(2 * M_PI * i / n);
    }

    // Implement FFT (simplified)
    // (Actual recursive call is now to s194_fft_recursive)
    s194_fft_recursive(real, imag, n);

    free(real);
    free(imag);
}

int main() {
    fft_signal_processing();
    return 0;
}
