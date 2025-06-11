// Snippet 5: Runge-Kutta method for solving ODEs
    void runge_kutta() {
        double h = 0.01, t = 0.0, y = 1.0;
        double k1, k2, k3, k4;
        int n = 1000;
        
        for (int i = 0; i < n; i++) {
            k1 = h * (t - y);
            k2 = h * (t + 0.5 * h - (y + 0.5 * k1));
            k3 = h * (t + 0.5 * h - (y + 0.5 * k2));
            k4 = h * (t + h - (y + k3));
            
            y = y + (k1 + 2*k2 + 2*k3 + k4) / 6.0;
            t += h;
        }
    }

int main() {
    runge_kutta();
    return 0;
}
