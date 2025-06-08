// 286.c
// Operaciones bitwise en un bucle (variación 13)
// Count set bits (Hamming weight) in a loop
int main() {
  volatile unsigned long long n = 0xAAAAAAAAAAAAAAAAULL;
  int total_set_bits = 0;
  for (long long i = 0; i < 1000000; ++i) {
    unsigned long long temp_n = n + i;  // Vary the number being checked
    int set_bits = 0;
    while (temp_n > 0) {
      temp_n &= (temp_n - 1);  // Brian Kernighan's algorithm
      set_bits++;
    }
    total_set_bits += set_bits;
  }
  return total_set_bits % 256;
}
