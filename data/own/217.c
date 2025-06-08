// 217.c
// Operaciones bitwise en un bucle (variación 1)
int main() {
  volatile unsigned long long val = 0xFEDCBA9876543210ULL;
  for (long long i = 0; i < 1500000; ++i) {
    val &= ~(1ULL << (i % 64));
    val |= ((i * i) % 0xFFFFFFULL);
  }
  return (int)(val % 256);
}
