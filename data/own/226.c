// 226.c
// Operaciones bitwise en un bucle (variación 3)
int main() {
  volatile unsigned long long val = 0xAABBCCDDEEFF0011ULL;
  for (long long i = 0; i < 1800000; ++i) {
    val = (~val) | (i & 0xFFFFFFULL);
    val = (val << 5) | (val >> (64 - 5));  // Rotate left 5 bits
  }
  return (int)(val % 256);
}
