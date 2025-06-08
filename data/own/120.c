// Snippet 10: Simpson's rule for numerical integration
    void simpsons_rule() {
        int n = 1000;
        double a = 0.0, b = 1.0, h, sum, result;
        
        h = (b - a) / n;
        sum = 1.0 / (1 + a) + 1.0 / (1 + b);
        
        // Simpson's rule
        for (int i = 1; i < n; i++) {
            if (i % 2 == 0) {
                sum += 2.0 / (1 + (a + i * h));
            } else {
                sum += 4.0 / (1 + (a + i * h));
            }
        }
        
        result = (h / 3.0) * sum;
    }

int main() {
    simpsons_rule();
    return 0;
}
