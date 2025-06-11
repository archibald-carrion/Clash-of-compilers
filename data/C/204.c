#include <math.h>   // For sin, cos
#include <stdlib.h> // For malloc, free
#include <stdio.h>  // For printf (if debugging)

// Define M_PI if not available in math.h
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Define a complex number type if not available
typedef struct {
    double real;
    double imag;
} complex_t;

// Recursive FFT function (Cooley-Tukey)
void s194_fft_recursive(complex_t *x, int N) {
    if (N <= 1) return;

    // Divide
    int k;
    complex_t *even = (complex_t*) malloc(N / 2 * sizeof(complex_t));
    complex_t *odd = (complex_t*) malloc(N / 2 * sizeof(complex_t));
    for (k = 0; k < N / 2; k++) {
        even[k] = x[k * 2];
        odd[k] = x[k * 2 + 1];
    }

    // Conquer
    s194_fft_recursive(even, N / 2);
    s194_fft_recursive(odd, N / 2);

    // Combine
    for (k = 0; k < N / 2; k++) {
        // Calculate twiddle factor using separate sin and cos calls
        double angle = 2.0 * M_PI * k / N;
        double cosVal = cos(angle);
        double sinVal = sin(angle);
        
        double t_real = cosVal * odd[k].real + sinVal * odd[k].imag;
        double t_imag = -sinVal * odd[k].real + cosVal * odd[k].imag;

        x[k].real = even[k].real + t_real;
        x[k].imag = even[k].imag + t_imag;
        x[k + N / 2].real = even[k].real - t_real;
        x[k + N / 2].imag = even[k].imag - t_imag;
    }

    free(even);
    free(odd);
}

void fft_signal_processing() {
    int N = 1024; // Size of the FFT, must be a power of 2
    complex_t *signal = (complex_t*) malloc(N * sizeof(complex_t));

    // Example: Create a simple signal (e.g., sum of sines)
    for (int i = 0; i < N; i++) {
        signal[i].real = sin(2 * M_PI * i / N * 5) + 0.5 * sin(2 * M_PI * i / N * 10); // Frequencies 5 and 10
        signal[i].imag = 0.0;
    }

    s194_fft_recursive(signal, N);

    // Output or further processing of 'signal' (which now contains FFT result)
    // For benchmark, just ensure the computation happens.

    free(signal);
}

int main() {
    fft_signal_processing();
    return 0;
}
