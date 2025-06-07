
// Snippet 3: Counting Set Bits (Hamming Weight)
void count_set_bits() {
    int n = 1000000;  // Number of integers to check
    int count = 0;

    for (int i = 0; i < n; i++) {
        int num = i;
        while (num) {
            count += num & 1;
            num >>= 1;
        }
    }
}
