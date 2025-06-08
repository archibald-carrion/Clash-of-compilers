// Snippet 9: Fibonacci Sequence (Recursive)
int fib(int n) {
    if (n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}

void fibonacci_recursive() {
    int n = 30;  // Calculate the first 30 Fibonacci numbers

    for (int i = 0; i < n; i++) {
        int result = fib(i);
    }
}

int main() {
    fibonacci_recursive();
    return 0;
}