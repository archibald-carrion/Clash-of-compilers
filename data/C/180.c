// Snippet 10: Finding the Greatest Common Divisor (GCD) Using Euclidean Algorithm
void gcd_euclidean() {
    int a = 12345678, b = 87654321;

    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
}

int main() {
    gcd_euclidean();
    return 0;
}
