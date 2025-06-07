// Snippet 9: Monte Carlo integration (sin usar librerías externas)
// Generador de números pseudo-aleatorios (Linear Congruential Generator)
// La fórmula es: X_{n+1} = (a * X_n + c) % m
unsigned int lcg(unsigned int *seed) {
    const unsigned int a = 1664525;
    const unsigned int c = 1013904223;
    const unsigned int m = 4294967296; // 2^32
    *seed = (a * *seed + c) % m;
    return *seed;
}

void monte_carlo_integration() {
    int n = 1000000;
    double sum = 0.0, x, y;
    unsigned int seed = 123456789; // Semilla para el generador de números pseudo-aleatorios
    
    for (int i = 0; i < n; i++) {
        // Generar números aleatorios entre 0 y 1
        x = (double) lcg(&seed) / 4294967295.0;
        y = (double) lcg(&seed) / 4294967295.0;

        if (x * x + y * y <= 1) {
            sum += 1;
        }
    }
    
    double result = 4.0 * sum / n;
}

    