// 298.c
// Operaciones bitwise en un bucle (variación 15)
// Bit reversal of a number
int main() {
  volatile unsigned int num_to_rev = 0x12345678;
  unsigned int reversed_num = 0;
  for (long long i = 0; i < 1000000; ++i) {
    unsigned int temp_num = num_to_rev + (unsigned int)i;
    reversed_num = 0;
    for (int j = 0; j < 32; ++j) {
      if ((temp_num >> j) & 1) {
        reversed_num |= (1U << (31 - j));
      }
    }
  }
  return (int)((num_to_rev ^ reversed_num) % 256);
}
