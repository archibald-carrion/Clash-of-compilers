// Snippet 4: Trapezoidal rule for numerical integration
    void trapezoidal_rule() {
        int n = 1000;  // Number of intervals
        double a = 0.0, b = 1.0, h, sum, result;
        
        h = (b - a) / n;
        sum = 0.5 * (1 / (1 + a) + 1 / (1 + b));
        
        // Trapezoidal rule
        for (int i = 1; i < n; i++) {
            sum += 1 / (1 + (a + i * h));
        }
        
        result = h * sum;
    }

int main() {
    trapezoidal_rule();
    return 0;
}
